/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements a list of processes (Customer objects) that are all waiting    */
/* for a specific event.                                                     */
/*****************************************************************************/

#include "waitingroom.h"
#include "../syscall/guarded_organizer.h"

Waitingroom::~Waitingroom() {
   while (head) {
       auto* customer = (Customer*)dequeue(); // since all members in the waitingroom are Customers it is auto = Customer
       guarded_organizer.wakeup(*customer);
   }
}

void Waitingroom::remove(Customer* customer) {
    Queue::remove((Chain*)(Entrant*)customer); // Customer is indirectly derived from Chain
    //set waiting room in removed item to NULLPTR
    customer->waiting_in(nullptr);
}