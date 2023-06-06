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


void Scheduler::ready (Entrant& that){
    this->rdy_list.enqueue(&that);
}
void Scheduler::schedule(){
    Chain* activated_obj = this->rdy_list.dequeue();
    if(activated_obj != nullptr){
        if (this->active() == nullptr) {
            this->go((Entrant&)(*activated_obj));
        }
        else {
            this->dispatch(*(Entrant*)(activated_obj)); /// why doesnt work other casting? : abstract class
        }
    }
}
void Scheduler::exit(){
    this->schedule();
}

void Scheduler::kill(Entrant& that){
    this->rdy_list.remove((Chain*)&that);
}


void Scheduler::resume(){
    Entrant* entrant = (Entrant*)(this->active());
    if(entrant){
        this->ready(*entrant);
        this->schedule();
    }
}

