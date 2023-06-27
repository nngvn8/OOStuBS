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
#include "../machine/key.h"
#include "../machine/plugbox.h"
#include "../machine/pic.h"
#include "../guard/gate.h"
#include "../object/queue.h"
#include "../object/o_stream.h"
#include "../guard/guard.h"


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

        // Add to buffer, for later printing
        if (key.valid()){
            this->prol_buf.produce(key);
        } else {
            return true;
        }
    }
}

void Keyboard::epilogue() {
    semaphore.signal();
}

Key Keyboard::getkey(){
    semaphore.wait();
    return this->prol_buf.consume();
}