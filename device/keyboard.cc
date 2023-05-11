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

void Keyboard::plugin(){
    // Connect to plugbox
    plugbox.assign(plugbox.keyboard, *this);
    // Tell pic to allow interrupts
    pic.allow(PIC::KEYBOARD);
}

bool Keyboard::prologue() {
    // Rerun until keyboard buffer is definitely empty
    while(true){
        Key key = keyboard_ctr.key_hit();

        // Check for ctrl + alt + del
        if (key.ctrl() && key.alt() && key.scancode()==Key::scan::del){
            keyboard_ctr.reboot();
        }

        // Immediately print the character to the screen for now
        if (key.valid()){
            cga.setpos(0,0);
            cga << key.ascii() << CGA_Stream::inst_print;
        } else{
            return true;
        }
    }
}
