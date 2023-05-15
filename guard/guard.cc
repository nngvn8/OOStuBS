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
#include "guard.h"
#include "../object/chain.h"
#include "../machine/cpu.h"
#include "secure.h"
#include "../guard/locker.h"

/*****************************************************************************/

void Guard::leave(){
    Gate* g;
    while(true) {
        cpu.disable_int();
        g = (Gate*) queue.dequeue();
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
        { //TODO review it!
            Secure section;
          item->epilogue();
        }
    } else {
        cpu.disable_int();
        if (!item->queued()) {
            item->queued(true);
            //TODO maybe too much, ask the tutors
            this->queue.enqueue((Chain*) item);
            cpu.enable_int();
        }

    }

}
