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

long stack[4096]; // the one global stack
#define COROUTINE_TOS_ONE 1024
#define COROUTINE_TOS_TWO 2048
#define COROUTINE_TOS_THREE 3072
#define COROUTINE_TOS_FOUR 4096

Thread1 thread1(&stack[COROUTINE_TOS_ONE], 100000000);
Thread2 thread2(&stack[COROUTINE_TOS_TWO],100000000);
Thread3 thread3(&stack[COROUTINE_TOS_THREE],100000000);
Thread4 thread4(&stack[COROUTINE_TOS_FOUR],100000000);

int main() {
    cpu.enable_int();
    keyboard.plugin();

    cga.clear_screen();

    // Testing the watch class
    //Watch watch{50000}; // close to maximum with 1/20 of a second
    //watch.windup();

    // Testing the threads
    guarded_scheduler.ready(thread1);
    guarded_scheduler.ready(thread2);
    guarded_scheduler.ready(thread3);
    guarded_scheduler.ready(thread4);

    guarded_scheduler.schedule();
    while(1){


    };

    return 0;
}
