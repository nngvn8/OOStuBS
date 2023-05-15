/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The system's central interrupt handling routine.                          */
/* The parameter specifies the number of the interrupt that occurred.        */
/*****************************************************************************/

#include "machine/keyctrl.h"
#include "machine/plugbox.h"
#include "guard.h"

extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.                                        */

void guardian (unsigned int slot){
    bool prologue_done = plugbox.report(slot).prologue();
    if (prologue_done) {
        //TODO call relay function
        //Guard::relay(plugbox.report(slot));
    }
}
