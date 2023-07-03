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

long stack[4096]; // the one global stack
#define COROUTINE_TOS_ONE 1024
#define COROUTINE_TOS_TWO 2048
#define COROUTINE_TOS_THREE 3072
#define COROUTINE_TOS_FOUR 4096

void printName(UserThread* t){
    cga << t->name << CGA_Stream::inst_print;
}

UserThread thread1(&stack[COROUTINE_TOS_ONE], 100, "a", &printName);
UserThread thread2(&stack[COROUTINE_TOS_TWO], 100, "b", &printName);
UserThread thread3(&stack[COROUTINE_TOS_THREE], 25000000, "c", &printName);
UserThread thread4(&stack[COROUTINE_TOS_FOUR], 25000000, "d", &printName);

int main() {
    Secure section;
    cpu.enable_int();
    keyboard.plugin();
    cga.clear_screen();



    // Testing the watch class
    // close to maximum with 1/20 of a second
    watch.windup();


    bellringer_test();

    // Testing the threads

    guarded_scheduler.Scheduler::ready(thread1);
    guarded_scheduler.Scheduler::ready(thread2);
    //guarded_scheduler.Scheduler::ready(thread3);
    //guarded_scheduler.Scheduler::ready(thread4);


    guarded_scheduler.Scheduler::schedule();

    while(1){


    };

    return 0;

}
