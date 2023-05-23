#include "machine/cpu.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "device/cgastr.h"
#include "user/appl.h"
#include "object/queue.h"
#include "guard/guard.h"
#include "thread/coroutine.h"

// Objects used everywhere => make them global
CPU cpu;
PIC pic;
Plugbox plugbox;
Keyboard keyboard;
CGA_Stream cga;
Panic global_panic{"Error?: Gate not initialized, Panic Obejct launched, see main()!"};
Guard guard;

long stack[4096]; // the one global stack
#define COROUTINE_TOS_ONE 0
#define COROUTINE_TOS_TWO 1024
#define COROUTINE_TOS_THREE 2048
#define COROUTINE_TOS_FOUR 3072

int main() {
    cpu.enable_int();
    keyboard.plugin();

    Coroutine c = Coroutine(&stack[COROUTINE_TOS_ONE]);

    Application app;
    app.action();
    //app.test_prologue_keyboard_char_buffer();

    while (1){}

    return 0;
}
