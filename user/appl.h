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
    char c;
public:
    Application(void* tos, char c) : Entrant(tos){
        //TODO warum kann man das nicht einfach so in den Konstruktr schreiben?
        this->c = c;

    } /// might not be inlined later on (explicit only because single argument)
    Application(const Application &copy) = delete; // prevent copying
 
	void action_interrupt_synchro();
    void action();
    void test_prologue_keyboard_char_buffer();
};

extern Application app1;
extern Application app2;
extern Application app3;
extern Application app4;


#endif
