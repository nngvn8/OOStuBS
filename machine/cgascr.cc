/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* This class allows accessing the PC's screen.  Accesses work directly on   */
/* the hardware level, i.e. via the video memory and the graphic adapter's   */
/* I/O ports.                                                                */
/*****************************************************************************/

#include "cgascr.h"
#include "io_port.h"

void CGA_Screen::move_up_screen(unsigned char attrib){
    // Do some pointer arithmatic to move all characters and attributes up by one line 
    for (int i = 1; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            char *pos_origin = (char *) 0xb8000 + 2*(j + i * 80);
            char *pos_target = (char *) 0xb8000 + 2*(j + (i-1) * 80);
            *pos_target = *pos_origin;
        }
    }
    // Clear last line
    for(int i = 0; i < 80; ++i){
        show(i, MAX_Y, '\0', attrib);
    }
}

void CGA_Screen::show(int x, int y, char c, unsigned char attrib){
    char *CGA_START = (char *) 0xb8000;
    char *pos = CGA_START + 2*(x + y * 80);
    *pos = c;
    *(pos + 1) = (char) attrib;
}

void CGA_Screen::setpos (int x, int y){
    // Wrap the x value to the next line specifically
    if (x>MAX_X){
        x = x % MAX_X;
        y++;
    }
    // Calculate the cursor offset from top left
    int rel_pos =  x + y * 80; // offset without attribute byte
    // Since errors can not be thrown yet, an illegal x and y combination will simply wrap around at the end
    rel_pos = rel_pos % ((MAX_X+1) * (MAX_Y+1));
    // Use IO_Port to write offset (set register then write to it)
    IO_Port index(INDEX_REGISTER_PORT);
    IO_Port data(DATA_REGISTER_PORT);
    index.outb(CURSOR_ADDRESS_LOW_INDEX);
    data.outb(rel_pos & 0xFF);
    index.outb(CURSOR_ADDRESS_HIGH_INDEX);
    data.outb((rel_pos >> 8) & 0xFF);
}

void CGA_Screen::getpos (int &x, int &y){
    // Use IO_Port to read offset (set register then read from it)
    IO_Port index(INDEX_REGISTER_PORT);
    IO_Port data(DATA_REGISTER_PORT);
    index.outb(CURSOR_ADDRESS_HIGH_INDEX);
    int rel_pos_high = data.inb();
    index.outb(CURSOR_ADDRESS_LOW_INDEX);
    int rel_pos_low = data.inb();
    int rel_pos = (rel_pos_high << 8) | rel_pos_low;
    // Calculate x and y from offset
    x = rel_pos % 80;
    y = (rel_pos - x) / 80;
}

void CGA_Screen::print (char* text, int length, unsigned char attrib){
    // Find current x and y coordinates
    int current_x, current_y;
    getpos(current_x, current_y);
    // Print all the characters
    for (int i = 0; i < length; ++i) {
        show(current_x, current_y, text[i], attrib);
        current_x++;
        if (current_x > MAX_X){
            current_x = 0;
            current_y++;
            if (current_y > MAX_Y){
                move_up_screen(attrib);
                current_y = MAX_Y;
            }
        }
    }
    // Set current cursor position once to be more performant
    setpos(current_x+1, current_y);
}
