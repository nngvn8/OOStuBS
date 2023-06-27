/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 B E L L                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Bell is an abstract base class that allows the time-controlled triggering */
/* of an activity. For this purpose, it has an internal counter that is      */
/* managed by the Bellringer.                                                */
/*****************************************************************************/

#ifndef __Bell_include__
#define __Bell_include__

#include "../object/chain.h"

class Bell : public Chain {
private:
    int ring_counter;

public:
	Bell(const Bell &copy) = delete; // prevent copying
	Bell() {}

    void wait(int value) { ring_counter = value; };
    int wait() { return ring_counter; };
    void tick() { ring_counter--;};
    bool run_down() { return ring_counter == 0; };
    virtual void ring() = 0;
};

#endif
