/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Using this class, we can synchronize activities with a critical section   */
/* with interrupt handlers that also access this critical section. This      */
/* synchronization takes place along the prologue/epilogue model.            */
/*****************************************************************************/

#include "guard.h"
#include "../object/chain.h"
#include "../machine/cpu.h"
#include "secure.h"
#include "../guard/locker.h"

void Guard::leave(){
    Gate* g;
    while(true) {
        cpu.disable_int();
        g = (Gate*) queue.dequeue();
        /// Do not enable interrupts here, because the gate might be null, which would delay the now new gate object
       // cpu.enable_int();

        if (g) {
           cpu.enable_int();
            g->queued(false);
            g->epilogue();
        }
        else {
            break;
        }
    }
    this->retne();
    cpu.enable_int();
}

void Guard::relay(Gate* item){
    if (this->avail()) {
        {
            Secure section;
            cpu.enable_int();
            item->epilogue();
        }
    } else {
        if (!item->queued()) {
            item->queued(true);
            this->queue.enqueue((Chain*) item);
        }
    }
}