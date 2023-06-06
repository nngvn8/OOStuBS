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

void Application::action(){
    //cga << "Hello World" << CGA_Stream::inst_print;
    while(1) {
        cga << this->c << '1' << CGA_Stream::inst_print;
        int ctr = 10000000;
        while(ctr){
            ctr--;
        }
        scheduler.resume();
        cga << this->c << '2' << CGA_Stream::inst_print;

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