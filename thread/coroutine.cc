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

#include "kickoff.h"
#include "coroutine.h"

// Functions that are implemented at C or assembler level must be declared as
// extern "C", because they do not conform to C++ name mangling.
extern "C" {
    void toc_go(struct toc* regs);
    void toc_switch(struct toc* regs_now, struct toc* reg_then);
    void toc_settle(struct toc *regs, void *tos,
                    void (*kickoff)(void *, void *, void *, void *, void *, void *, void *),
                    void *object);
}

Coroutine::Coroutine(void* tos){
    coroutine_regs = {0,0,0,0,0,0,0,0}; /// not sure whether or not initialization with zero or not
    toc_settle(&coroutine_regs, tos, &kickoff, this);
}

void Coroutine::go() {
    toc_go(&coroutine_regs);
}

void Coroutine::resume(Coroutine& next) {
    toc_switch(&this->coroutine_regs, &next.coroutine_regs);
}