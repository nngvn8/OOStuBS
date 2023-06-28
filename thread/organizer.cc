/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Organizer is a special scheduler that additionally allows processes   */
/* (Customer objects) to wait for events (Waitingroom objects).              */
/*****************************************************************************/

#include "organizer.h"

void Organizer::block(Customer& customer, Waitingroom& waitingroom) {
    /// Order?
    Scheduler::kill(customer);
    customer.waiting_in(&waitingroom);
    Scheduler::schedule();
}

void Organizer::wakeup(Customer& customer) {
    /// Order?
    /// merge lines two and three?
    Scheduler::ready(customer);
    Waitingroom* waitingroom = customer.waiting_in();
    waitingroom->remove(&customer);
}

void Organizer::kill(Customer& that) {
    Waitingroom* waitingroom = that.waiting_in();
    if (waitingroom) {
        waitingroom->remove(&that);
    }
    else {
        Scheduler::kill(that);
    }
}
