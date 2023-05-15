/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "guard/gate.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "cgastr.h"
#include "utils/kb_prologue_char_buf.h"
#include "../object/chain.h"
 
class Keyboard : public Gate, public Chain{
private:
    Keyboard_Controller keyboard_ctr = Keyboard_Controller();
    Kb_prologue_char_buf prol_buf;
public:
	Keyboard(){}
    Keyboard(const Keyboard &copy) = delete; // prevent copying
 
	// PLUGIN: "Plugs in" the keyboard (driver). From now on, keypresses are handled.
    void plugin();
    virtual bool prologue ();
    virtual void epilogue ();

};

extern Keyboard keyboard;

#endif
