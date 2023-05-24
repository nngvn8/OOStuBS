/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 T O C                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The toc struct is used to save the values of the non-volatile registers   */
/* in case of a context switch. toc_settle prepares the initial stack and    */
/* the toc struct for the first activation.                                  */
/*****************************************************************************/

#include "machine/toc.h"

// TOC_SETTLE: Prepares a coroutine context for its first activation.
void toc_settle(struct toc *regs, void *tos,
		void (*kickoff)(void *, void *, void *, void *, void *, void *, void *),
		void *object){
    // Must be void** because void has no size => no pointer arithmetic, but void* has a size
    void** p = (void**) tos;  // tos must be one larger than the last array element (because always decrement first)
    *(--p) = object;  // seventh parameter for kickoff function
    *(--p) = (void*) 0;  // return address, which should never be called
    *(--p) = kickoff;  // return address, which should be called
    toc->rsp = p;  // Saving the current stack pointer in the toc struct
}
