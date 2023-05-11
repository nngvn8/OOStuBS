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
        //TODO enqueue when first character inserted and not enqueued

        if (key.valid()){
            prol_buf.produce(key.ascii());
            if(!this->queued()){
                queue.enqueue(this);
            }

        } else{
            return true;
        }
    }
}

void Keyboard::epilogue() {
    //TODO: when the queue is finished this has to be implemented
    return;
}
