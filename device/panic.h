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
#include "machine/cpu.h"
#include "guard/gate.h"

class Panic : public Gate{
private:
    char* msg;
    char* id = "panic";

public:
    Panic (char* message) : msg(message){}
    Panic (const Panic &copy) = delete; // prevent copying

    bool prologue ();
    char* getID(){return id;}


};

extern Panic global_panic;

#endif
