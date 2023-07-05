#include "machine/cpu.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "device/cgastr.h"
#include "user/appl.h"
#include "object/queue.h"
#include "guard/guard.h"
#include "thread/coroutine.h"
#include "thread/dispatch.h"
#include "thread/scheduler.h"
#include "thread/threads.h"
#include "device/watch.h"
#include "guard/secure.h"
#include "syscall/guarded_scheduler.h"
#include "thread/organizer.h"
#include "meeting/semaphore.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_organizer.h"
#include "meeting/bellringer.h"
#include "meeting/buzzer.h"
#include "syscall/guarded_buzzer.h"

// Objects used everywhere => make them global
CPU cpu;
PIC pic;
Plugbox plugbox;
Keyboard keyboard;
CGA_Stream cga;
Panic global_panic{"Error?: Gate not initialized, Panic Obejct launched, see main()!"};
Guard guard;
Dispatcher dispatcher;
Scheduler scheduler;
Guarded_Scheduler guarded_scheduler;
Bellringer bellringer;
Watch watch{1000000};
Guarded_Organizer guarded_organizer;
Guarded_Semaphore printing_semaph(1);

long stack[4096]; // the one global stack
#define COROUTINE_TOS_ONE 1024
#define COROUTINE_TOS_TWO 2048
#define COROUTINE_TOS_THREE 3072
#define COROUTINE_TOS_FOUR 4096

void printName(UserThread* t){
    int i = 0;
    int slowing_factor = 3000000;
    while (true) {
        printing_semaph.p();
        while (t->msg[i] != '\0') {
                cga << t->msg[i] << CGA_Stream::inst_print;
            i++;
            for (int j=0; j < slowing_factor; j++);
        }
        cga << CGA_Stream::endl;

        t->wait_timer--;
        if (!t->wait_timer) {
            Guarded_Buzzer buzzer;
            buzzer.set(1000);
            cga << t->name << " sleeping now" << CGA_Stream::endl;
            buzzer.sleep();
            cga << t->name << " awake now" << CGA_Stream::endl;
        }

        i = 0;
        printing_semaph.v();
    }

}

//void idle(UserThread* t) {
//    while (true) {
//        cga << "I dont do anything" << CGA_Stream::endl;
//    }
//}


UserThread thread1(&stack[COROUTINE_TOS_ONE], 2, "ONE", "ONE: Hello I am thread one,ONE: \0", &printName);
UserThread thread2(&stack[COROUTINE_TOS_TWO], 3, "TWO", "TWO: Hello I am thread two,TWO: \0", &printName);
UserThread thread3(&stack[COROUTINE_TOS_THREE], 5, "THREE", "THREE: Hello I am thread three,THREE: \0", &printName);
//UserThread thread4(&stack[COROUTINE_TOS_FOUR], 5, "FOUR", "THREE: Hello I am thread three,THREE: \0", &idle);

int main() {
    Secure section;
    cpu.enable_int();
    keyboard.plugin();
    cga.clear_screen();


    // Testing the watch class
    // close to maximum with 1/20 of a second
    watch.windup();


    guarded_organizer.Scheduler::ready(thread1);
    guarded_organizer.Scheduler::ready(thread2);
    guarded_organizer.Scheduler::ready(thread3);
//    guarded_organizer.Scheduler::ready(thread4);

    guarded_organizer.Scheduler::schedule();

    while(1);

    return 0;

}
