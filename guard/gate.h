/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Class of objects that handle interrupts.                                  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

#include "device/cgastr.h"
#include "machine/cpu.h"
#include "object/chain.h"

//wird irgednwie ehe initialisiert als andere in der main
class Gate : public Chain{
private:
    bool is_in_q = 0;
public:
    virtual bool prologue () = 0;
    virtual void epilogue (){};
    void queued (bool q){
        if(is_in_q == q){
            //error case!
            cga << "In Gate: Error on queued, state: " << is_in_q << CGA_Stream::endl;
            //TODO : right error case, cannot use panic since its dervied from Gate
            cpu.halt();
        }
        else{
            is_in_q = q;
        }
    }
    bool queued (){
        return is_in_q;
    }
    virtual char* getID() = 0;
};


#endif
