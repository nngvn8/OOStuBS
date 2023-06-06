/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "../thread/dispatch.h"
#include "../object/chain.h"
#include "entrant.h"
#include "../object/queue.h"

class Scheduler : public Dispatcher {
private:
    Queue rdy_list;
public:
	Scheduler (const Scheduler &copy) = delete; // prevent copying
    Scheduler(){}
    void ready(Entrant& that);
    void schedule();
    void exit();
    void kill(Entrant& that);
    void resume();
};

extern Scheduler scheduler;

#endif
