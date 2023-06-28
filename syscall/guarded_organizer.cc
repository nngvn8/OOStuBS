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

void Guarded_Organizer::block(Customer& customer, Waitingroom& waitingroom) {
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
}