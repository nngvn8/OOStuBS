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
#include "machine/pic.h"
#include "../utils/kb_prologue_char_buf.h"

void Application::action(){
    cga.clear_screen();

    while(true){
        cpu.disable_int();
        cga.setpos(35, 11);
        //enter
        //prolog wird der buffer gefüllt weil ein interrupt vom keyboard kommt mit ascii zeichen
        cga << "Hello World!" << CGA_Stream::inst_print;
        //hier kann der Buffer nicth gestört
        //epilogue: buffer wird gelehrt und allesgedruckt
        cpu.enable_int();
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

