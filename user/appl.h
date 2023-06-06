/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "thread/coroutine.h"
#include "thread/entrant.h"

/// CURRENTLY DIRECTLY DERIVES FROM COROUTINE
class Application : public Entrant {
private:
public:
    Application(void* tos) : Entrant(tos){
        //TODO warum kann man das nicht einfach so in den Konstruktr schreiben?

    } /// might not be inlined later on (explicit only because single argument)
    Application(const Application &copy) = delete; // prevent copying
 
	void action_interrupt_synchro();
     virtual void action() = 0;
    void test_prologue_keyboard_char_buffer();
};




#endif
