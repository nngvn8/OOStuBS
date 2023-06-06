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

    /**
     * Queues that in ready list of scheduler
     * @param that
     */
    void ready(Entrant& that);

    /**
     * Pops Entrant form ready list and continues/starts it
     */
    void schedule();

    /**
     * Schedules next Entrant WITHOUT appending current one
     */
    void exit();

    /**
     * Remove Entrant that from ready list
     * @param that
     */
    void kill(Entrant& that);

    /**
     * Schedules next Entrant WITH appending current one
     */
    void resume();
};

extern Scheduler scheduler;

#endif
