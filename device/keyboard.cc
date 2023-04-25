/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

#include "keyboard.h"

extern Plugbox plugbox;
extern PIC pic;

void Keyboard::plugin(){
    // Connect to plugbox
    plugbox.assign(Plugbox::keyboard, this);
    // Tell pic to allow interrupts
    pic.allow(PIC::KEYBOARD);
}

void Keyboard::trigger(){
    cga << "Key was hit" << CGA_Stream::endl;
}