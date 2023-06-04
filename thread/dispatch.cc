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
    if (life_pointer != nullptr) {
        life_pointer = &first;
        first.go();
    }
    else {
        dispatch(first);
    }
}

void Dispatcher::dispatch(Coroutine& next) {
    // maybe call go() if life_pointer == null?
    auto intermediate_ptr = life_pointer;
    life_pointer = &next;
    (*intermediate_ptr).resume(next);
}

Coroutine* Dispatcher::active() {
    return life_pointer;
}
