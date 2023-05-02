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
/* Add your code here */ 
 
/* GLOBAL VARIABLES */

extern CGA_Stream cga;
/* Add your code here */ 
 
void Application::action(){
    cga.clear_screen();

    while(true){
        cga.setpos(35, 11);
        cga << "Hello World!";
    }
}
