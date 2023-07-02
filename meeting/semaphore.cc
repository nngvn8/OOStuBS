/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The class Semaphore implements the synchronization concept of the         */
/* counting semaphore.                                                       */
/*****************************************************************************/

#include "semaphore.h"
#include "../device/panic.h"
#include "../thread/organizer.h"


Semaphore::Semaphore(int c) : semaphore_val(c) {
    if (c < 0) {
        global_panic.prologue("Can not assign Semaphore with value smaller than zero!");
    }
}

void Semaphore::p() {
    if (semaphore_val) {
        semaphore_val--;
    }
    else {
        auto* active_customer = (Customer*)organizer.Dispatcher::active();
        organizer.block(*active_customer, *this);
    }
}

void Semaphore::v() {
    if (head) {
        organizer.wakeup(*(Customer*)head);
    }
    else {
        semaphore_val++;
    }
}

void Semaphore::wait() {
    if (semaphore_val) {
        semaphore_val--;
    }
    else {
        auto* active_customer = (Customer*)organizer.Dispatcher::active();
        organizer.block(*active_customer, *this);
    }
}

void Semaphore::signal() {
    if (head) {
        organizer.wakeup(*(Customer*)head);
    }
    else {
        semaphore_val++;
    }
}
