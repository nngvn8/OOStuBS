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

    // Check for ctrl + alt + del
    if (key.ctrl() && key.alt() && key.scancode()==Key::scan.del){
        keyboard_ctr.reboot();
    }

    // Immediately print the character to the screen for now
    if (key.valid()){
        cga << key.ascii();
        cga.flush();
    }
}
