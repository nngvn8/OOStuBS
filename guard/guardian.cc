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

#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/plugbox.h"

/* FUNCTIONS */

// central interrupt handling routine
// processor jumps to a wrapper routine which calls guardian
// passing th number of the corresponding interrupt as a parameter
// all interrupts lead to call teh guardian


extern "C" void guardian (unsigned int slot);

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.                                        */

void guardian (unsigned int slot){
    CGA_Stream cgaStream = CGA_Stream();
    Plugbox pbox = Plugbox();
    cgaStream << "[Guardian] Interrupt occurred" << O_Stream::endl;
    pbox.report(slot).trigger();

}
