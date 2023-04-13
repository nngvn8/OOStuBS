#include "machine/cgascr.h"
#include "tests/cga_wrapping_test.h"
#include "tests/keyboard_test.h"

void string_buff_and_o_strem_test_application(){
    // TODO: Implement
}

void cga_stream_test_application(){
    // TODO: Implement
}

int main() {
    cga_wrapping_test();

    test();

    string_buff_and_o_strem_test_application();

    cga_stream_test_application();

    // TODO: Add routine for choosing a test to run, via keyboard input

	return 0;
}
