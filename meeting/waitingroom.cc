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
#include "../thread/organizer.h"

Waitingroom::~Waitingroom() {
   while (head) {
       auto* customer = (Customer*)dequeue(); // since all members in the waitingroom are Customers it is auto = Customer
       organizer.wakeup(*customer);
   }
}

void Waitingroom::remove(Customer* customer) {
    Queue::remove(customer); // Customer is indirectly derived from Chain
}