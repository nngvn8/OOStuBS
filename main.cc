#include "tests/flashy_test.h"
#include "machine/cpu.h"
#include "machine/pic.h"

int main() {
    CPU cpu = CPU();
    cpu.enable_int();
    PIC pic = PIC();
    pic.allow(1); // allow keyboard

    // test_all_tests();

    while (1){}

    return 0;
}
