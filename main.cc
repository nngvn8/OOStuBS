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

long stack[4096]; // the one global stack
#define COROUTINE_TOS_ONE 1024
#define COROUTINE_TOS_TWO 2048
#define COROUTINE_TOS_THREE 3072
#define COROUTINE_TOS_FOUR 4096

Thread1 thread1(&stack[COROUTINE_TOS_ONE]);
Thread2 thread2(&stack[COROUTINE_TOS_TWO]);
Thread3 thread3(&stack[COROUTINE_TOS_THREE]);
Thread4 thread4(&stack[COROUTINE_TOS_FOUR]);



int main() {
    cpu.enable_int();
    keyboard.plugin();

    // Initial coroutine test


    //app1.action_interrupt_synchro();
    //app.test_prologue_keyboard_char_buffer();
    cga.clear_screen();
    scheduler.ready(thread1);
    scheduler.ready(thread2);
    scheduler.ready(thread3);
    scheduler.ready(thread4);

    scheduler.schedule();



    return 0;
}
