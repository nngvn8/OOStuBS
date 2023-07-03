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


class Customer : public Entrant {
private:
    Waitingroom* waitingroom = nullptr;
public:
	Customer (const Customer &copy) = delete; // prevent copying
    /// constructor taking @parameter tos
    using Entrant::Entrant;

    void waiting_in(Waitingroom* w) {
        if (waitingroom) {
            if (waitingroom == w) {
                return;
            }
            else {
                w->remove(this);
            }
        }
        waitingroom = w;
        w->enqueue(this);
    }

    Waitingroom* waiting_in() {
        /// nullptr return with: setting it initially to nullptr and setting it to nullptr in Waitingroom::remove()
        /// -> thereby value should always be consistent
        /// only has to be returned here
        return waitingroom;
    }
};

#endif
