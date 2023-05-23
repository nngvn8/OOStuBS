/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          C O R O U T I N E                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Represents the abstraction of a coroutine.                                */
/* In the constructor, we set up the initial context of the coroutine. go()  */
/* activates the first coroutine. All further coroutine switches should be   */
/* initiated by resume().                                                    */
/* To be able to save the context at a couroutine switch, every Coroutine    */
/* object contains a struct toc that stores the values of all non-volatile   */
/* registers.                                                                */
/*****************************************************************************/

#include "thread/coroutine.h"
#include "thread/kickoff.h"

void Coroutine::go() {
    // TODO: call toc_go(); with parameter
}

void Coroutine::resume(Coroutine& next) {
    // TODO: call toc_switch() with parameters
}