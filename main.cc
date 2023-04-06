#include "machine/cgascr.h"

void clear_screen(){
    CGA_Screen cga_screen = CGA_Screen();
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            cga_screen.show(j, i, 'X', 0xFF);
        }
    }
    cga_screen.setpos(0, 0);
}

void cgascr_test_application(){
    // Initialize the one CGA_Screen
    CGA_Screen cga_screen = CGA_Screen();

    // Show a white S to "GRUB" into "GRUBS"
    cga_screen.show(4,8, 'S', 0x0F);

    // TODO: Test Attribute for blinking

    // Move cursor one step to the right (dynamic)
    int x = 0;
    int y = 0;
    cga_screen.getpos(x, y);
    cga_screen.setpos(x+1, y);
    cga_screen.getpos(x, y);
    cga_screen.show(x,y,'X',0x02);
    cga_screen.setpos(x+1, y);
}

void print_hello_message(){
    clear_screen();
    CGA_Screen cga_screen = CGA_Screen();
    char message[] = "Hello, World!"
    cga_screen.print(message, 13, 0x02);
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
