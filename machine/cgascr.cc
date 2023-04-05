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

/* Add your code here */ 
#include "machine/cgascr.h"

/* Add your code here */



void CGA_Screen::show(int x, int y, char c, unsigned char attrib){
    char *CGA_START = (char *) 0xb8000;
    char *pos;
    pos = CGA_START + 2*(x + y * 80);
    *pos = c;
    *(pos + 1) = (char) attrib;
}

void CGA_Screen::setpos (int x, int y){

}

void CGA_Screen::print (char* text, int length, unsigned char attrib){

}