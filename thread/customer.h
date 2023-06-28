/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C U S T O M E R                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Customer class extends the Entrant class with the ability to record   */
/* and retrieve an event that the process in question is waiting for.        */
/*****************************************************************************/

#ifndef __customer_include__
#define __customer_include__

#include "entrant.h"
#include "meeting/waitingroom.h"

class Waitingroom; // TODO remove this (currently does not work without)

class Customer : public Entrant {
public:
	Customer (const Customer &copy) = delete; // prevent copying
    /// constructor taking @parameter tos
    using Entrant::Entrant;

    void waiting_in(Waitingroom* w) { waitingroom = w; }
    Waitingroom* waiting_in () {
        /* TODO return 0 when not waiting for any event (bestcase: waitingroom == nullptr iff not waiting for event)
        otherwise case distinction */
        return waitingroom;
    }

private:
    Waitingroom* waitingroom;
};

#endif
