/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Handles timer interrupts by managing a time slice and triggering a        */
/* process switch if necessary.                                              */
/*****************************************************************************/

#include "watch.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "syscall/guarded_scheduler.h"
#include "../meeting/bellringer.h"

// For debugging
#include "cgastr.h"
#include "../syscall/guarded_scheduler.h"
#include "../object/o_stream.h"

int counter = 0;
int y =0;

void Watch::windup(){
    plugbox.assign(plugbox.timer, *this);
    pic.allow(PIC::TIMER);
}

bool Watch::prologue(){
    // Do nothing except triggering the epilogue
    return true;
}

void Watch::epilogue(){
    if (counter ==20) {
        //cga.setpos(0, y);
        //y++;
        cga << "Timer interrupted!" << CGA_Stream::endl;
        counter = 0;

        bellringer.check();
        //guarded_scheduler.Scheduler::resume();

    }else{
        counter++;
    }

}
