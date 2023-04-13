//
// Created by martin on 4/13/23.
//
#include "machine/keyctrl.h"
#include "device/cgastr.h"

//#ifndef OOSTUBBS_MBJ_KEYBOARD_TEST_H
//#define OOSTUBBS_MBJ_KEYBOARD_TEST_H

void test () {
    Keyboard_Controller contrlr =  Keyboard_Controller();
    CGA_Stream cga = CGA_Stream();

    while (true) {
        Key test_key = contrlr.key_hit();
        cga << (char)test_key.ascii() << CGA_Stream::endl;
    }


}

//#endif //OOSTUBBS_MBJ_KEYBOARD_TEST_H


