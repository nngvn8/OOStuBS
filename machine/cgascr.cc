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

void CGA_Screen::move_up_screen(unsigned char attrib_of_last_line){
    // Do some pointer arithmetic to move all characters and attributes up by one line
    int line_width_bytes = 2 * LINE_WIDTH;
    for (int i = 1; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < line_width_bytes; ++j) {
            char *pos_origin = (char *) 0xb8000 + (j + i * line_width_bytes);
            char *pos_target = (char *) 0xb8000 + (j + (i-1) * line_width_bytes);
            *pos_target = *pos_origin;
        }
    }
    // Clear last line
    for(int i = 0; i < LINE_WIDTH; ++i){
        show(i, MAX_Y, '\0', attrib_of_last_line);
    }
}

void CGA_Screen::show(int x, int y, char c, unsigned char attrib){
    char *CGA_START = (char *) 0xb8000;
    char *pos = CGA_START + 2*(x + y * LINE_WIDTH);
    *pos = c;
    *(pos + 1) = (char) attrib;
}

void CGA_Screen::setpos (int x, int y){
    // Wrap the x value to the next line specifically
    if (x>MAX_X){
        x = x % (MAX_X+1);
        y++;
    }
    // Calculate the cursor offset from top left
    int rel_pos =  x + y * LINE_WIDTH; // offset without attribute byte
    // Since errors can not be thrown yet, an illegal x and y combination will simply wrap around at the end
    rel_pos = rel_pos % (LINE_WIDTH * SCREEN_HEIGHT);
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
    x = rel_pos % LINE_WIDTH;
    y = (rel_pos - x) / LINE_WIDTH;
}

void CGA_Screen::line_break(int &current_x, int &current_y, unsigned char attrib){
    // Actually move to next line
    current_x = 0;
    current_y++;
    // Make room for new line at the bottom
    if(current_y > MAX_Y){
        move_up_screen(attrib);
        current_y = MAX_Y;
    }
}

void CGA_Screen::print (char* text, int length, unsigned char attrib){
    // Find and copy current x and y coordinates
    int current_x, current_y;
    getpos(current_x, current_y);
    // Print all the characters
    for (int i = 0; i < length; ++i) {
        if (text[i]=='\n'){
            line_break(current_x, current_y, attrib);
            continue;
        }
        if (current_x > MAX_X){
            line_break(current_x, current_y, attrib);
        }
        show(current_x, current_y, text[i], attrib);
        current_x++;
    }
    // Set current cursor position once to be more performant
    setpos(current_x, current_y);
}
