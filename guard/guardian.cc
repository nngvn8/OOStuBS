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

extern "C" void guardian (unsigned int slot);
extern Plugbox plugbox; // declare global object to exist somewhere

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.                                        */

void guardian (unsigned int slot){
    CGA_Stream cgaStream = CGA_Stream();
    cgaStream << "[Guardian] Interrupt occurred" << O_Stream::endl;
    plugbox.report(slot).trigger();
}
