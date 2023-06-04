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

void Application::action(){
    while(1) {
        cga << this->c << CGA_Stream::inst_print;
        switch (this->c) {
            case 'a':
                //if app 1
                dispatcher.dispatch(app2);
                break;
            case 'b':
                //if app 2
                dispatcher.dispatch(app3);
                break;
            case 'c':
                //if app 3
                dispatcher.dispatch(app4);
                break;
            case 'd':
                //if app 4
                dispatcher.dispatch(app1);
                break;
        }
    }

}

void Application::test_prologue_keyboard_char_buffer(){
    cga.clear_screen();

    Kb_prologue_char_buf ch_buf = Kb_prologue_char_buf();

    pic.forbid(PIC::KEYBOARD);
    cga.setpos(0, 0);

    ch_buf.produce('a');

    ch_buf.produce('b');
    ch_buf.produce('c');

    cga << "Consume first char, now should be a" << CGA_Stream::endl;
    cga << ch_buf.consume() << CGA_Stream::endl;
    cga << "Consume second char, now should be b" << CGA_Stream::endl;
    cga << ch_buf.consume() << CGA_Stream::endl;
    cga << "Consume second char, now should be c" << CGA_Stream::endl;
    cga << ch_buf.consume() << CGA_Stream::endl;
    cga << "Consume second char, nothing more in the buffer" << CGA_Stream::endl;
    cga << ch_buf.consume() << CGA_Stream::endl;
}