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
#include "tests/bellringer_test.h"
#include "thread/organizer.h"
#include "meeting/semaphore.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_organizer.h"

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
Watch watch{50000};
Guarded_Organizer guarded_organizer;
Guarded_Semaphore printing_semaph(1);

long stack[4096]; // the one global stack
#define COROUTINE_TOS_ONE 1024
#define COROUTINE_TOS_TWO 2048
#define COROUTINE_TOS_THREE 3072
#define COROUTINE_TOS_FOUR 4096

void printName(UserThread* t){
    int i = 0;
    int slowing_factor = 6000000;
    while (true) {
        printing_semaph.p();
        while (t->msg[i] != '\0') {
                cga << t->msg[i] << CGA_Stream::inst_print;
            i++;
            for (int j=0; j < slowing_factor; j++);
        }
        cga << '\n' << CGA_Stream::inst_print;

        i = 0;
        printing_semaph.v();
    }

}


UserThread thread1(&stack[COROUTINE_TOS_ONE], 100, "ONE", "ONE: Hello I am thread one,ONE: \0", &printName);
UserThread thread2(&stack[COROUTINE_TOS_TWO], 100, "TWO", "TWO: Hello I am thread two,TWO: \0", &printName);
UserThread thread3(&stack[COROUTINE_TOS_THREE], 100, "THREE", "THREE: Hello I am thread three,THREE: \0", &printName);
UserThread thread4(&stack[COROUTINE_TOS_FOUR], 25000000, "d", "d", &printName);

int main() {
    Secure section;
    cpu.enable_int();
    keyboard.plugin();
    cga.clear_screen();

//    // show address of printing_semaphore
//    cga << "Printing_semaphore: " << &printing_semaph << CGA_Stream::endl;
//    cga << "Adress Thread1: " << &thread1 << CGA_Stream::endl;
//    cga << "Adress Thread2: " << &thread2 << CGA_Stream::endl;


    // Testing the watch class
    // close to maximum with 1/20 of a second
    watch.windup();


    bellringer_test();

    // Testing the threads

    guarded_organizer.Scheduler::ready(thread1);
    guarded_organizer.Scheduler::ready(thread2);
    guarded_organizer.Scheduler::ready(thread3);
    //guarded_organizer.Scheduler::ready(thread4);


    guarded_organizer.Scheduler::schedule();

    while(1){


    };

    return 0;

}
