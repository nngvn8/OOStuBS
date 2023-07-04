/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ O R G A N I Z E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Guarded_Organizer implements the system call interface to the         */
/* Organizer.                                                                */
/*****************************************************************************/

#include "guarded_organizer.h"
#include "../guard/secure.h"

/*void Guarded_Organizer::block(Customer& customer, Waitingroom& waitingroom) {
    Secure section;
    Organizer::block(customer, waitingroom);
}

void Guarded_Organizer::wakeup(Customer& customer) {
    Secure section;
    Organizer::wakeup(customer);
}

void Guarded_Organizer::kill(Customer& that) {
    Secure section;
    Organizer::kill(that);

}*/

void Guarded_Organizer::ready (Thread& that){
    Secure section;
    Scheduler::ready(that);
}

void Guarded_Organizer::exit (){
    Secure section;
    Scheduler::exit();
}

void Guarded_Organizer::kill (Thread& that){
    Secure section;
    Scheduler::kill(that);
}

void Guarded_Organizer::resume(){
    Secure section;
    Scheduler::resume();
}
