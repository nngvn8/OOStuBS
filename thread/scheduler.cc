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
    auto activated_obj = this->rdy_list.dequeue();
  //TODO morgen in der Übg durchquatschen
}
void Scheduler::exit (){
    this->schedule();
}
void Scheduler::kill (Entrant& that){
    this->rdy_list.remove( (Chain*)&that);
}
void Scheduler::resume(){
    this->rdy_list.enqueue(((Chain*)dispatcher.active()));
    this->schedule();
}

