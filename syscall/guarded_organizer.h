/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ O R G A N I Z E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Guarded_Organizer implements the system call interface to the         */
/* Organizer.                                                                */
/*****************************************************************************/

#ifndef __Guarded_Organizer_include__
#define __Guarded_Organizer_include__

#include "../syscall/thread.h"
#include "../thread/organizer.h"

class Guarded_Organizer : public Organizer {
public:
	Guarded_Organizer() {}
	Guarded_Organizer(const Guarded_Organizer &copy) = delete; // prevent copying

    void block(Customer& customer, Waitingroom& waitingroom);
    void wakeup(Customer& customer);
    void kill(Customer& that);
};

extern Guarded_Organizer guarded_organizer;

#endif
