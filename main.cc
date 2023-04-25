#include "tests/flashy_test.h"
#include "machine/plugbox.h"
#include "machine/cpu.h"
#include "guard/gate.h"

int main() {

    CPU cpu = CPU();
    cpu.enable_int();
    test_all_tests();

    return 0;
}
