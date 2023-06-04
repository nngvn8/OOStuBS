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

/* Add your code here */

class Scheduler: public Dispatcher
/* Add your code here */ 
{
public:
	Scheduler (const Scheduler &copy) = delete; // prevent copying
    void ready (Entrant& that);
    void schedule ();
    void exit ();
    void kill (Entrant& that);
    void resume ();
 
};

#endif
