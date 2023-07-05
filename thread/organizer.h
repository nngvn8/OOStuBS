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
#include "customer.h"
#include "../meeting/waitingroom.h"
#include "../thread/threads.h"
void idle(UserThread* t);
class Organizer : public Scheduler
{
public:
    long stack_idle_thread[1024];
    UserThread idle_thread{&stack_idle_thread[1024], 0, "idle", "", &idle};

	Organizer(const Organizer &copy) = delete; // prevent copying
	Organizer() {}

    /// why takes parameter if blocking CURRENTLY RUNNING process?
    void block(Customer& customer, Waitingroom& waitingroom);
    void wakeup(Customer& customer);
    void kill(Customer& that);

};

extern Organizer organizer;

#endif
