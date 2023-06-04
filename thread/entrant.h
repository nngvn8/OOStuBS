/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            E N T R A N T                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* A coroutine that is managed by the Scheduler.                             */
/*****************************************************************************/

#ifndef __entrant_include__
#define __entrant_include__

#include "coroutine.h"
#include "../object/chain.h"

/* Add your code here */

class Entrant: public Coroutine, Chain
/* Add your code here */ 
{
public:
	Entrant(const Entrant &copy) = delete; // prevent copying
    Entrant (void* tos);
/* Add your code here */ 
};

#endif
