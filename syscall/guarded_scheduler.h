/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S C H E D U L E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements the system-call interface to the Scheduler.                    */
/*****************************************************************************/

#ifndef __guarded_scheduler_include__
#define __guarded_scheduler_include__

#include "../thread/scheduler.h"
#include "thread.h"


class Guarded_Scheduler: public Scheduler
{
public:
    Guarded_Scheduler () {};
    Guarded_Scheduler(const Guarded_Scheduler &copy) = delete; // prevent copying
    void ready (Thread& that);
    void exit ();
    void kill (Thread& that);
    void resume ();
    void schedule();


};

extern Guarded_Scheduler guarded_scheduler;

#endif
