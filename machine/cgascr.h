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
#define LINE_WIDTH 80
#define SCREEN_HEIGHT 25
#define INDEX_REGISTER_PORT 0x3d4
#define DATA_REGISTER_PORT 0x3d5
#define CURSOR_ADDRESS_HIGH_INDEX 14
#define CURSOR_ADDRESS_LOW_INDEX 15

class CGA_Screen {
private:

    /**
     * Copies everything (char and attrib) from the second line to the first and so on.
     * Also clears the last line in one color.
     * @param attrib is the color in which the last line will be formatted
     */
    void move_up_screen(unsigned char attrib_of_last_line);

    /**
     * Changes the first two parameters to be a new line, while testing if the screen needs to be scrolled up
     * @param current_x is the offset from the beginning of the line, which should be changed
     * @param current_y is the line number, which should be changed
     * @param attrib is the color in which the last line will be formatted, if the scrolling occurs
     */
    void line_break(int &current_x, int &current_y, unsigned char attrib);

public:
    CGA_Screen(){}

	CGA_Screen(const CGA_Screen &copy) = delete; // prevent copying

    /**
     * Shows an ascii character at the position x, y
     * @param x is the offset from the beginning of the line, between 0 and 79
     * @param y is the line number between 0 and 24
     * @param c is the ascii character
     * @param attrib is the color for the foreground (last four bits) and background (first four bits)
     */
    void show(int x, int y, char c, unsigned char attrib);

    /**
     * Sets the cursor to the position x, y
     * @param x is the offset from the beginning of the line, between 0 and 79
     * @param y is the line number between 0 and 24
     * @warning If the x or y parameter are out of bounds, wrapping will occur
     */
    void setpos (int x, int y);

    /**
     * Writes the current position values x and y of the cursor to the references given
     * @param x reference to the x component of the cursor position - offset from the beginning of the line
     * @param y reference to the y component of the cursor position - line number
     */
    void getpos (int &x, int &y);

    /**
     * Prints the given text in one color beginning at the current position of the cursor, and resets the cursor
     * to one space after the last character
     * @param text a pointer to a char array, containing the text
     * @param length the number of character in the 'text' parameter (note that chars like newline are one character)
     * @param attrib is the color for the foreground (last four bits) and background (first four bits)
     * @warning if the length is to short, chars will be cut off and if it is too long, spaces will be printed
     */
    void print (char* text, int length, unsigned char attrib);

};

#endif
