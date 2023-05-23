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

#ifndef __Coroutine_include__
#define __Coroutine_include__

#include "machine/toc.h"

class Coroutine {
public:
    Coroutine(const Coroutine &copy) = delete; // prevent copying

    /**
     * Initializes the stack pointer to point to tos and on first activation execution begins with the kickoff function
     * @param tos top o' stack
     */
    Coroutine(void* tos);

    /**
     * Used for the first activation of the first coroutine in the system, therefore no register values must be saved here
     */
    void go();

    /**
     * Triggers a coroutine switch.
     * Saves the current contents of the non-volatile registers into the toc element and replaces them by the
     * values of the next coroutine
     * @param next the next coroutine to be called
     */
    void resume(Coroutine& next);

    /**
     * Actually performs the job of the coroutine.
     * To enable different actions to be implemented, things functions must be implemented in Application
     */
    virtual void action() = 0;
};

#endif