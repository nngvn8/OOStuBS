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
#include "dispatch.h"

/*****************************************************************************/

void Dispatcher::go(Coroutine& first) {
    // check if go has been called although a coroutine is already running -> call dispatch() instead
    life_pointer = &first;
    first.action();

}

void Dispatcher::dispatch(Coroutine& next) {
    Coroutine* life_ptr_prev = life_pointer;
    life_pointer = &next;
    life_ptr_prev->resume(next);
}

Coroutine* Dispatcher::active() {
    return this->life_pointer;
}
