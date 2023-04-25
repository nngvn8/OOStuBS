#include "machine/cpu.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "device/cgastr.h"

// Objects used everywhere => make them global
CPU cpu = CPU();
PIC pic = PIC();
Plugbox plugbox = Plugbox();
Keyboard keyboard = Keyboard();
CGA_Stream cga = CGA_Stream();

int main() {
    cpu.enable_int();
    keyboard.plugin();

    // test_all_tests();

    while (1){}

    return 0;
}
