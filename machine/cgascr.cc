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

void CGA_Screen::show(int x, int y, char c, unsigned char attrib){
    char *CGA_START = (char *) 0xb8000;
    char *pos = CGA_START + 2*(x + y * 80);
    *pos = c;
    *(pos + 1) = (char) attrib;
}

void CGA_Screen::setpos (int x, int y){
    // Since errors can not be thrown yet, an illegal x and y value will simply wrap around at the end
    int current_x = x % MAX_X;
    int current_y = y % MAX_Y;
    // Calculate the cursor offset from top left
    int rel_pos =  current_x + current_y * 80; // offset without attribute bit
    // Use IO_Port to write offset
    IO_Port index(INDEX_REGISTER_PORT);
    IO_Port data(DATA_REGISTER_PORT);
    index.outb(CURSOR_ADDRESS_LOW_INDEX);
    data.outb(rel_pos & 0xFF);
    index.outb(CURSOR_ADDRESS_HIGH_INDEX);
    data.outb((rel_pos >> 8) & 0xFF);
}

void CGA_Screen::getpos (int &x, int &y){
    // Use IO_Port to read offset
    IO_Port index(INDEX_REGISTER_PORT);
    IO_Port data(DATA_REGISTER_PORT);
    index.outb(CURSOR_ADDRESS_HIGH_INDEX);
    int rel_pos_high = data.inb();
    index.outb(CURSOR_ADDRESS_LOW_INDEX);
    int rel_pos_low = data.inb();
    int rel_pos = (rel_pos_high << 8) | rel_pos_low;
    // Calculate x and y from offset
    int local_x = rel_pos % 80;
    int local_y = (rel_pos - local_x) / 80;
    x = local_x;
    y = local_y;
}

void CGA_Screen::print (char* text, int length, unsigned char attrib){
    // TODO: Implement
}
