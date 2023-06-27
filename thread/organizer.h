/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Organizer is a special scheduler that additionally allows processes   */
/* (Customer objects) to wait for events (Waitingroom objects).              */
/*****************************************************************************/

#ifndef __organizer_include__
#define __organizer_include__

#include "scheduler.h"
class Organizer : public Scheduler
{
public:
	Organizer(const Organizer &copy) = delete; // prevent copying
	Organizer() {}
};

#endif
