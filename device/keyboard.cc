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
extern CGA_Stream cga;

void Keyboard::plugin(){
    // Connect to plugbox
    plugbox.assign(plugbox.keyboard, *this);
    // Tell pic to allow interrupts
    pic.allow(PIC::KEYBOARD);
}

void Keyboard::trigger(){
    Key key = keyboard_ctr.key_hit();
    if (key.valid()){
        cga << key.ascii();
        cga.flush();
    }
}
