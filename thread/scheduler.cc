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
#include "device/cgastr.h"
#include "threads.h"


void Scheduler::ready(Entrant& that) {
    this->rdy_list.enqueue(&that);
}

void Scheduler::schedule() {
    Chain* activated_obj = this->rdy_list.dequeue();
    if (activated_obj != nullptr) {
        if (this->active() == nullptr) {
//            cga << "In GO " << ((UserThread*)activated_obj)->name << CGA_Stream::endl;
            this->go((Coroutine&)(Entrant&)(*activated_obj)); /// can cast on reference of abstract class (due pointer internally)
        }
        else {
//            cga << "In DISPATCH " << ((UserThread*)activated_obj)->name << CGA_Stream::endl;
            this->dispatch((Coroutine&)*(Entrant*)(activated_obj)); /// cant cast on abstract class
        }
    }
    else {
        cga << "tried to schedule NULL" << CGA_Stream::endl;
    }
}

void Scheduler::exit() {
    this->schedule();
}

void Scheduler::kill(Entrant& that) {
    if ((Coroutine*)&that == active()) {
        this->exit();
    }
    else {
        this->rdy_list.remove((Chain*)&that);
    }
}

void Scheduler::resume() {
    auto entrant = (Entrant*)(this->active());
    if (entrant) {
        this->ready(*entrant);
        this->schedule();
    }
}
