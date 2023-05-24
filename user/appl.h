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

/// CURRENTLY DIRECTLY DERIVES FROM COROUTINE
class Application : public Coroutine {

public:
    explicit Application (void* tos) : Coroutine(tos) {} /// might not be inlined later on (explicit only because single argument)
    Application(const Application &copy) = delete; // prevent copying
 
	void action();
    void test_prologue_keyboard_char_buffer();
};

#endif
