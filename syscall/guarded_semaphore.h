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

#ifndef __Guarded_Semaphore_include__
#define __Guarded_Semaphore_include__

#include "../meeting/semaphore.h"
#include "../guard/secure.h"

class Guarded_Semaphore : public Semaphore {
public:
	Guarded_Semaphore(const Guarded_Semaphore &copy) = delete; // prevent copying
    using Semaphore::Semaphore;

    void p();
    void v();
    void wait();
    void signal();
    int get_val() {Secure section; return semaphore_val;}
};

#endif
