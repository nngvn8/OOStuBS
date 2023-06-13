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
int counter = 0;

void Watch::windup(){
    plugbox.assign(plugbox.timer, *this);
    pic.allow(PIC::TIMER);
}

bool Watch::prologue(){
    // Do nothing except triggering the epilogue
    return true;
}

void Watch::epilogue(){
    if (counter == 20) {
        cga << "Timer interrupted!" << CGA_Stream::endl;
        counter = 0;
    }else{
        counter++;
    }
    
    // guarded_scheduler.resume();
}
