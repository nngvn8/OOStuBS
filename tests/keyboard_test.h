//
// Created by martin on 4/13/23.
//
#include "machine/keyctrl.h"
#include "device/cgastr.h"

//#ifndef OOSTUBBS_MBJ_KEYBOARD_TEST_H
//#define OOSTUBBS_MBJ_KEYBOARD_TEST_H

unsigned char user_answer(char* user_input) {

}


void set_led_test(Keyboard_Controller &contrlr, CGA_Stream &cga) {
    unsigned char key_content = 'n';

    while (key_content != 'y') {
        cga << "Select a LED! (caps_lock (4), num_lock (2), scroll_lock(1))" << CGA_Stream::endl;
        key_content = contrlr.key_hit().ascii();
        cga << key_content << CGA_Stream::endl;
        while (key_content != '4' && key_content != '2' && key_content != '1') {
            cga << "Type '4', '2' or '1' to select the corresponding LED!" << CGA_Stream::endl;
            key_content = contrlr.key_hit().ascii();
            cga << key_content << CGA_Stream::endl;
        }
        char led = (char) (key_content - 48);
//    cga << led << CGA_Stream::endl;

        cga << "Select Mode! (on (1), off(0))" << CGA_Stream::endl;
        key_content = contrlr.key_hit().ascii();
        cga << key_content << CGA_Stream::endl;
        while (key_content != '1' && key_content != '0') {
            cga << "Type '1' or '0' to choose if the LED is on or off!" << CGA_Stream::endl;
            key_content = contrlr.key_hit().ascii();
            cga << key_content << CGA_Stream::endl;
        }
        bool on = (bool) (key_content - 48);
//        cga << on << CGA_Stream::endl;

        contrlr.set_led(led, on);

        cga << "Do you want to exit? [y/N]" << CGA_Stream::endl;
        key_content = contrlr.key_hit().ascii();
        cga << key_content << CGA_Stream::endl;
    }
    cga << "You left the LED test!" << CGA_Stream::endl;
}

void keyboard_test() {
    Keyboard_Controller contrlr =  Keyboard_Controller();
    CGA_Stream cga = CGA_Stream();
    unsigned char key_content = '0';

    set_led_test(contrlr, cga);

    while (key_content != 'x') {
        key_content = contrlr.key_hit().ascii();
        cga << key_content << CGA_Stream::endl;
    }


}



//#endif //OOSTUBBS_MBJ_KEYBOARD_TEST_H


