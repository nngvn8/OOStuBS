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

Application app1(&stack[COROUTINE_TOS_ONE], 'a');
Application app2(&stack[COROUTINE_TOS_TWO], 'b');
Application app3(&stack[COROUTINE_TOS_THREE], 'c');
Application app4(&stack[COROUTINE_TOS_FOUR], 'd');



int main() {
    cpu.enable_int();
    keyboard.plugin();

    // Initial coroutine test


    //app1.action_interrupt_synchro();
    //app.test_prologue_keyboard_char_buffer();

    scheduler.ready(app1);
    scheduler.ready(app2);
    scheduler.ready(app3);
    scheduler.ready(app4);

    scheduler.schedule();



    return 0;
}
