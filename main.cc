#include "machine/cpu.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "device/cgastr.h"
#include "user/appl.h"

// Objects used everywhere => make them global
CPU cpu = CPU();
PIC pic = PIC();
Plugbox plugbox = Plugbox();
Keyboard keyboard = Keyboard();
CGA_Stream cga = CGA_Stream();

int main() {
    cpu.enable_int();
    keyboard.plugin();

    Application app = Application();

    app.action();

    while (1){}

    return 0;
}
