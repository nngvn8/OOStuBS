/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/
#include "panic.h"

extern CPU cpu; // declare global to exist somewhere
extern CGA_Stream cga;

void Panic::trigger() {
    cga << msg << CGA_Stream::endl;
    cpu.halt();
}
