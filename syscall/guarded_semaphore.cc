/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S E M A P H O R E                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Guarded_Semaphore class implements the system call interface to the   */
/* Semaphore class.                                                          */
/*****************************************************************************/

#include "guarded_semaphore.h"
#include "../guard/secure.h"

void Guarded_Semaphore::p() {
    Secure section;
    Semaphore::p();
}

void Guarded_Semaphore::v() {
    Secure section;
    Semaphore::v();

}

void Guarded_Semaphore::wait() {
    Secure section;
    Semaphore::wait();
}

void Guarded_Semaphore::signal() {
    Secure section;
    Semaphore::signal();
}
