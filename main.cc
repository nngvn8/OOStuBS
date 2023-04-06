#include "machine/cgascr.h"

void cgascr_test_application(){
    // Initialize the one CGA_Screen
    CGA_Screen cga_screen = CGA_Screen();

    // Show a white S to "GRUB" into "GRUBS"
    cga_screen.show(4,8, 'S', 0x0F);

    // TODO: Test Attribute for blinking

    // Move cursor one step to the right (hardcoded)
    cga_screen.setpos(6, 8);

    /*
    For later debugging

    // Move cursor one step to the right (dynamic)
    int x, y;
    cga_screen.getpos(&x, &y);
    cga_screen.setpos(x+1, y);
     */
}

void string_buff_and_o_strem_test_application(){
    // TODO: Implement
}

void cga_stream_test_application(){
    // TODO: Implement
}

int main() {
    cgascr_test_application();

    string_buff_and_o_strem_test_application();

    cga_stream_test_application();
 
	return 0;
}
