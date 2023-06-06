/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Dispatcher implementation.                                                */
/* The Dispatcher maintains the life pointer that points to the currently    */
/* active coroutine. go() initializes the life pointer and starts the first  */
/* coroutine, all further context switches are triggered by dispatch().      */
/* active() returns the life pointer.                                        */
/*****************************************************************************/

#ifndef __dispatch_include__
#define __dispatch_include__

#include "coroutine.h"

class Dispatcher {
private:
    Coroutine* life_pointer;

public:
	Dispatcher(const Dispatcher &copy) = delete; // prevent copying
    Dispatcher() : life_pointer(nullptr){}

    /**
     * Sets life_pointer to first and starts it (call toc_settle())
     * @param first Coroutine to be executed
     */
    void go(Coroutine& first);

    /**
     * Sets life_pointer to next and switches from current coroutine to next
     * @param next Coroutine to be executed
     */
    void dispatch(Coroutine& next);

    /**
     * Returns currently running coroutine
     */
    Coroutine* active();
};

extern Dispatcher dispatcher;


#endif
