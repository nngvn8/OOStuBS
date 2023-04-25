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
    plugbox.assign(plugbox.keyboard, *this);
    // Tell pic to allow interrupts
    pic.allow(PIC::KEYBOARD);
}

void Keyboard::trigger(){
    CGA_Stream cga = CGA_Stream(); // TODO: remove debugging statement

    Key key = keyboard_ctr.key_hit();

    if (key.valid()){
        cga << key.ascii();
    }
}
