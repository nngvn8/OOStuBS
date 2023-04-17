#include "machine/cgascr.h"
<<<<<<< HEAD
//#include "tests/cga_wrapping_test.h"
//#include "tests/keyboard_test.h"
#include "tests/flashy_test.h"


int main() {
    // cga_wrapping_test();

    // test();

    test_all_tests();


    // TODO: Add routine for choosing a test to run, via keyboard input
=======
#include "tests/cga_wrapping_test.h"
#include "tests/keyboard_test.h"
#include "tests/o_stream_test.h"


int main() {
    // keyboard_test();
    // cga_wrapping_test();
    // o_stream_hello_w();
    cga_stream_edge_case_test();
    // cga_stream_color_setting_test();
>>>>>>> origin/main

	return 0;
}
