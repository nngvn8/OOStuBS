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
#include "secure.h"

extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.                                        */

void guardian (unsigned int slot){
    Gate* gate_ptr = &plugbox.report(slot) ;

    /// Never print in Guardian, because it is even before the prologue. Weird things will happen!
    //cga.setpos(0,0);
    //cga << "We are in the guardian" << CGA_Stream::endl;

    if (gate_ptr->prologue()) // return value expresses: do epilogue or not
        guard.relay(gate_ptr);
}