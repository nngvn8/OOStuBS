/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
 
void Application::action(){
    cga.clear_screen();

    while(true){
        cpu.disable_int();
        cga.setpos(35, 11);
        cga << "Hello World!" << CGA_Stream::inst_print;
        cpu.enable_int();
    }
}
