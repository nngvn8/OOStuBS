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
#include "syscall/guarded_sheduler.h"

// For debugging
#include "cgastr.h"

void Watch::windup(){
    plugbox.assign(plugbox.timer, *this);
    pic.allow(PIC::TIMER);
}

void Watch::prologue(){
    // Do nothing
}

void Watch::epilogue(){
    cga << "Timer interrupted!" << CGA_Stream::endl();
    // guarded_scheduler.resume();
}