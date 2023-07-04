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

/* Add your code here */

class Bell: public Chain
/* Add your code here */
{
protected:
    int internal_counter;

public:

    Bell(const Bell &copy) = delete; // prevent copying
    Bell() {
        this->internal_counter = 0;
    }

    void wait (int value){
        this->internal_counter = value;
    }
    int wait (){
        return this->internal_counter;
    }
    void tick (){
        this->internal_counter --;
    }
    //TODO == 0 or <= 0 ?
    bool run_down(){
        return this->internal_counter == 0;
    }
    virtual void ring () = 0;

};

#endif
