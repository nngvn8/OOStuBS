//
// Created by martin on 4/13/23.
//
#include "machine/keyctrl.h"
#include "device/cgastr.h"

//#ifndef OOSTUBBS_MBJ_KEYBOARD_TEST_H
//#define OOSTUBBS_MBJ_KEYBOARD_TEST_H

void set_led_test(Keyboard_Controller contrlr, CGA_Stream cga) {
//
//    cga << "Select a LED! (caps_lock, num_lock, scroll_lock)" << CGA_Stream::endl;
//
//    cga << "Select Mode! (on, off)" << CGA_Stream::endl;
//
//    contrlr.set_led(4,1);
//    contrlr.set_led(1,1);
//    contrlr.set_led(2,1);
//    contrlr.set_led(2,0);
//    contrlr.set_led(4,0);
//    contrlr.set_led(1,0);
}

void keyboard_test() {
    Keyboard_Controller contrlr =  Keyboard_Controller();
    CGA_Stream cga = CGA_Stream();

    while (true) {
        Key test_key = contrlr.key_hit();
        cga << (char)test_key.ascii() << CGA_Stream::endl;
    }

//    set_led_test(contrlr, cga);
}



//#endif //OOSTUBBS_MBJ_KEYBOARD_TEST_H


