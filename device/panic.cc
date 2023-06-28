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
#include "../object/o_stream.h"
#include "../machine/cpu.h"
#include "../device/cgastr.h"

bool Panic::prologue() {
    cga << msg << CGA_Stream::endl;
    cpu.halt();
    return true;
}

bool Panic::prologue(char* message) {
    cga << message << CGA_Stream::endl;
    cpu.halt();
    return true;
}