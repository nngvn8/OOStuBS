/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K I C K O F F                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Function to start a coroutine.                                            */
/* Since this function is not really called, but only jumped to by a clever  */
/* initialization of the stack of the coroutine, it must never terminate.    */
/* Otherwise a meaningless value would be interpreted as a return address    */
/* and the computer would crash.                                             */
/*****************************************************************************/

#include "../thread/kickoff.h"
#include "coroutine.h"
#include "../device/panic.h"


/// "realizes jump from C to C++ level"?
void kickoff(void* dummy1, void* dummy2, void* dummy3, void* dummy4, void* dummy5, void* dummy6, Coroutine* object) {
    object->action();

    // make sure the kickoff function can never return to the invalid value
    Panic panic("Tried to leave kickoff function!");
    panic.prologue();
}
 
