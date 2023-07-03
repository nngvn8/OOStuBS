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
    customer.waiting_in(&waitingroom);
    Scheduler::kill(customer);
    Scheduler::schedule();
}

void Organizer::wakeup(Customer& customer) {
    /// Order?
    /// merge lines two and three?
    Waitingroom* waitingroom = customer.waiting_in();
    waitingroom->remove(&customer);
    Scheduler::ready((Entrant&)customer);

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
