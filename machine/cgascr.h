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

class CGA_Screen {
private:
/* Add your code here */ 

public:
	CGA_Screen(const CGA_Screen &copy) = delete; // prevent copying
    //hier war ein default contructor
    void show(int x, int y, char c, unsigned char attrib);

    void setpos (int x, int y);

    void print (char* text, int length, unsigned char attrib);

};

/* Add your code here */ 

#endif
