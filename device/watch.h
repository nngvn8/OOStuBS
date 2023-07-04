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

#ifndef __watch_include__
#define __watch_include__

/* INCLUDES */

#include "guard/gate.h"
#include "machine/pit.h"

class Watch : public Gate, public PIT {
private:
    char* id = "timer";

public:
	Watch(const Watch &copy) = delete; // prevent copying

    /**
     * Initializes a timer, which periodically interrupts at intervals of approximately us microseconds
     * @param us  number of microseconds
     */
    Watch(int us) : PIT(us) {}

	/**
	 * "Winds up" the clock, by registering with the plugbox and allow the interrupts of the timer
	 * module with the help of the global pic object.
	 */
    void windup();

	/**
	 * ???
	 */
	bool prologue();

    /**
     * Triggers the process switch.
     */
	void epilogue();

    /**
     * A debug tool to distinguish the different threads
     * @return ID as string
     */
    char* getID(){
        return id;
    }
};

extern Watch watch;

#endif
