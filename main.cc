#include "machine/cpu.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"

// Objects used everywhere => make them global
CPU cpu = CPU();
PIC pic = PIC();
Plugbox plugbox = Plugbox();
Keyboard keyboard_ctr = Keyboard(); // must be weirdly named because of enum in pic

int main() {
    cpu.enable_int();
    pic.allow(1); // allow keyboard

    // test_all_tests();

    while (1){}

    return 0;
}
