#include "machine/cgascr.h"
#include "tests/cga_wrapping_test.h"
#include "tests/keyboard_test.h"
#include "tests/o_stream_test.h"


int main() {
    // keyboard_test();
    // cga_wrapping_test();
    // o_stream_hello_w();
    cga_stream_edge_case_test();
    // cga_stream_color_setting_test();

	return 0;
}
