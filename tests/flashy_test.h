//
// Created by Julius Gilka-Bötzow on 13.04.23.
//

#include "device/cgastr.h"
#include "machine/keyctr.h"
#include "cga_wrapping_test.h"

/// The idea of this class is to encompass all other test and make them be callable by the user



void test_all_tests(){
    clear_screen(); // from wrapping test

    CGA_Stream cga = CGA_Stream();
    Keyboard_Controller keyboard = Keyboard_Controller();

    cga << "Welcome. Please select a program. We have:" << CGA_Stream::endl;
    cga << "1. Wrapping test" << CGA_Stream::endl;
    cga << "2. Keyboard test (currently never ending)" << CGA_Stream::endl;
    cga << "Please input one of the numbers to select a program" << CGA_Stream::endl;
    Key number = keyboard.key_hit();
    switch (number.ascii()) {
        case '1':
            cga << "Selected 1" << CGA_Stream::endl;
            break;
        case '2':
            cga << "Selected 2" << CGA_Stream::endl;
            break;
        default:
            cga << "Your input was " << number.ascii() << ", which is supported" << CGA_Stream::endl;
            break;
    }
}