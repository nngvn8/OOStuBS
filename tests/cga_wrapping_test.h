//
// Created by Julius Gilka-Bötzow on 11.04.23.
//

#include "machine/cgascr.h"

static void clear_screen(){
    CGA_Screen cga_screen = CGA_Screen();
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            cga_screen.show(j, i, '\0', 0x02);
        }
    }
    cga_screen.setpos(0, 0);
}

static void cga_wrapping_test(){
    clear_screen();
    CGA_Screen cga_screen = CGA_Screen();
    char message[] = "This line should get cut off.";
    char message2[] = "This used to be the fourth line.";
    char message3[] = "This message ends at the end of line";
    char message4[] = "Cursor";
    char message5[] = "This message wraps around.";
    char message6[] = "\nThis message has a line break\nIn the middle\n";
    cga_screen.setpos(0, 0);
    cga_screen.print(message, 29, 0x02);
    cga_screen.setpos(0, 4);
    cga_screen.print(message2, 32, 0x02);
    cga_screen.setpos(44, 5);
    cga_screen.print(message3, 36, 0x02);
    cga_screen.print(message4, 6, 0x02);
    cga_screen.setpos(67, 24);
    cga_screen.print(message5, 25, 0x02);
    cga_screen.print(message6, 45, 0x02);
}


