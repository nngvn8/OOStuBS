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
    cpu.disable_int();
    Gate* gate_ptr = &plugbox.report(slot);
    cga << "Das ist die ID: " << gate_ptr->getID() << CGA_Stream::endl;

    if (gate_ptr->prologue()) {
        cpu.enable_int();
        guard.relay(gate_ptr);
    } else cpu.enable_int();
}
