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
#include "../thread/threads.h"


Semaphore::Semaphore(int c) : semaphore_val(c) {
    if (c < 0) {
        global_panic.prologue("Can not assign Semaphore with value smaller than zero!");
    }
}

void Semaphore::p() {
    if (semaphore_val) {
        semaphore_val--;
        auto* active_customer = (Customer*)organizer.active();
        cga << "Active Customer (semaphore_val > 0): " << active_customer << CGA_Stream::endl;
    }
    else {
        auto* active_customer = (Customer*)organizer.active();
//        cga << "Active Customer Before: " << organizer.Dispatcher::active() << CGA_Stream::endl;
        cga << "Active Customer (semaphore_val = 0, BEFORE Block): " << active_customer << CGA_Stream::endl;
        organizer.block(*active_customer, *this);
//        cga << ((UserThread*)active_customer)->getName() << CGA_Stream::endl;
//        ((UserThread*)active_customer)->getName();
        cga << "Active Customer (semaphore_val = 0, BEFORE Block): " << active_customer << CGA_Stream::endl;
        cga << "Waiting_in after block: " << active_customer->waiting_in() << CGA_Stream::endl;
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
