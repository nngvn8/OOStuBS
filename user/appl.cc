/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/


#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "machine/pic.h"
#include "../utils/kb_prologue_char_buf.h"
#include "guard/secure.h"
#include "machine/plugbox.h"
#include "thread/dispatch.h"
#include "thread/scheduler.h"

void Application::action_interrupt_synchro(){
    cga.clear_screen();
    while(true){
        {
            Secure section; // guard enter aka setting it unavailable
            cga.setpos(35, 11);
            cga << "Hello World!" << CGA_Stream::inst_print;

        } // On destruction of Secure, the guard, will call all epilogues and set itself available
    }
}