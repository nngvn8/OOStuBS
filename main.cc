#include "machine/cpu.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "device/cgastr.h"
#include "user/appl.h"

// Objects used everywhere => make them global
CPU cpu;
PIC pic;
Plugbox plugbox;
Keyboard keyboard;
CGA_Stream cga;
Panic global_panic{"Error: Gate not initialized!"};

int main() {
    cpu.enable_int();
    keyboard.plugin();

    Application app;

    app.action();

    while (1){}

    return 0;
}
