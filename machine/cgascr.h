#ifndef __screen_include__
#define __screen_include__

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

#include "machine/io_port.h"

#define MAX_X 79
#define MAX_Y 24
#define INDEX_REGISTER_PORT 0x3d4
#define DATA_REGISTER_PORT 0x3d5
#define CURSOR_ADDRESS_HIGH_INDEX 14
#define CURSOR_ADDRESS_LOW_INDEX 15

class CGA_Screen {
private:
    void move_up_screen();

public:
    CGA_Screen(){}
	CGA_Screen(const CGA_Screen &copy) = delete; // prevent copying

    void show(int x, int y, char c, unsigned char attrib);

    void setpos (int x, int y);

    void getpos (int &x, int &y);

    void print (char* text, int length, unsigned char attrib);

};

#endif
