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
    this->rdy_list.enqueue( (Chain*)&that);
}
void Scheduler::schedule(){
    Chain* activated_obj = this->rdy_list.dequeue();
    if(activated_obj != nullptr){
        if(this->active() == nullptr){
            this->go(*(Coroutine*)(Entrant*)(activated_obj));
        } else{
            this->dispatch(*(Coroutine*)(Entrant*)(activated_obj)); /// why doesnt work other casting?
        }
    }

}
void Scheduler::exit (){
    this->schedule();
}
void Scheduler::kill (Entrant& that){
    this->rdy_list.remove( (Chain*)&that);
}


void Scheduler::resume(){
    Entrant* entrant = static_cast<Entrant*>(this->active());
    if(entrant){
        this->ready(*entrant);
        this->schedule();
    }

}

