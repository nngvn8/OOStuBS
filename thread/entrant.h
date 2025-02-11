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

class Entrant : public Coroutine, public Chain {
public:
	Entrant(const Entrant &copy) = delete; // prevent copying
    using Coroutine :: Coroutine; // deriving constructor from Coroutine; equivalent to Entrant (void* tos) : Coroutine(tos) {};
};

#endif
