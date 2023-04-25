/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

#include "cgastr.h"
#include "../machine/cpu.h"

class Panic : public Gate{
private:
    char* msg;
    CGA_Stream cga();
    CPU cpu();

public:
	Panic (const Panic &copy) = delete; // prevent copying
	Panic (char* message) : msg(message){}

    void trigger();
 
};

#endif
