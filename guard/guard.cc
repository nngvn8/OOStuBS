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
        item->epilogue();
    }
    else {
        if (!item->queued()) {
            item->queued(true);
            queue.enqueue((Chain*)item);
        }
    }

}
