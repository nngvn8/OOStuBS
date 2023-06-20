/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#include "scheduler.h"


void Scheduler::ready(Entrant& that) {
    this->rdy_list.enqueue(&that);
}

void Scheduler::schedule() {
    Chain* activated_obj = this->rdy_list.dequeue();
    if (activated_obj != nullptr) {
        if (this->active() == nullptr) {
            this->go((Entrant&)(*activated_obj)); /// can cast on reference of abstract class (due pointer internally)
        }
        else {
            this->dispatch(*(Entrant*)(activated_obj)); /// cant cast on abstract class
        }
    }
}

void Scheduler::exit() {
    this->schedule();
}

void Scheduler::kill(Entrant&1 that) {
    this->rdy_list.remove((Chain*)&that);
}

void Scheduler::resume() {
    auto entrant = (Entrant*)(this->active());
    if (entrant) {
        this->ready(*entrant);
        this->schedule();
    }
}
