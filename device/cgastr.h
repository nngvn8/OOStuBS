/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C G A _ S T R E A M                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The CGA_Stream class allows to print different data types as text strings */
/* to a PC's CGA screen.                                                     */
/* For attributes/colors and cursor positioning use the methods of class     */
/* CGA_Screen.                                                               */
/*****************************************************************************/

#ifndef __cgastr_include__
#define __cgastr_include__

#include "object/o_stream.h"
#include "machine/cgascr.h"

enum CGA_COLORS{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_YELLOW = 14,
    WHITE = 15
};


class CGA_Stream: public O_Stream, public CGA_Screen{
private:
    unsigned char current_text_colour = 0x0F; // Initialize to white on black

public:
  CGA_Stream(){};
	CGA_Stream(CGA_Stream &copy) = delete; // prevent copying

    /**
     * Writes the buffer to the CGA screen in the currently selected color.
     * Can be called directly or by shifting "endl" into the buffer.
     */
    void flush();

     /**
      * Sets the fore- and background color for the next time the buffer will be flushed.
      * For all options see CGA_COLORS.
      * @param foreground color of the ascii symbol
      * @param background color behind the ascii symbol
      * @param is_blinking makes the symbol blink (does not work in qemu)
      */
    void set_current_text_colour(CGA_COLORS foreground, CGA_COLORS background, bool is_blinking);

    /**
     * Prints the empty ascii symbol to every part of the screen in the current text color
     */
    void clear_screen();
};

#endif