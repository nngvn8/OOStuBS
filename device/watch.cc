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

// For debugging
#include "cgastr.h"
#include "../syscall/guarded_scheduler.h"
#include "../syscall/guarded_organizer.h"

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
//    if (counter == 60) {
        //cga.setpos(0, y);
//        y++;
        //cga << "Timer interrupted!" << CGA_Stream::endl;
//        counter = 0;

        guarded_organizer.Scheduler::resume();

        //guarded_scheduler.Scheduler::resume();

//    }else{
//        counter++;
//    }

}
