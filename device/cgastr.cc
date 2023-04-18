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

#include "device/cgastr.h"

void CGA_Stream::flush(){
    //this->string ohne irgendwas gibt mir den pointer auf den anfang
    this->print(this->string, this->index, this->current_text_colour);
    this->index = 0;
}

void CGA_Stream::set_current_text_colour(CGA_COLORS foreground, CGA_COLORS background, bool is_blinking){
    this->current_text_colour = ((unsigned char)is_blinking << 7) | ((background & 0b111) << 4) | (foreground & 0b1111);
}

void CGA_Stream::clear_screen(){
    clear_screen_with(current_text_colour);
}
