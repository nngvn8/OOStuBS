//
// Created by Julius Gilka-Bötzow on 13.04.23.
//

#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "cga_test.h"
#include "keyboard_test.h"
#include "o_stream_test.h"

/// The idea of this class is to encompass all other test and make them be callable by the user

void test_all_tests(){
    CGA_Stream cga = CGA_Stream();
    Keyboard_Controller keyboard = Keyboard_Controller();

    while (true){
        clear_screen(); // from wrapping test

        cga << "Welcome. Please select a program. We have:" << CGA_Stream::endl;
        cga << "1. Screen wrapping test" << CGA_Stream::endl;
        cga << "2. Keyboard test (ending with q)" << CGA_Stream::endl;
        cga << "3. Edge case test of cga stream" << CGA_Stream::endl;
        cga << "4. Testing the cga stream manipulators" << CGA_Stream::endl;
        cga << "5. Testing the colors of the cga stream" << CGA_Stream::endl;
        cga << "6. Running the hello_w program for the cga stream" << CGA_Stream::endl;
        cga << "Please input one of the numbers to select a program." << CGA_Stream::endl;
        cga << "Rerun this prompt by hitting any button." << CGA_Stream::endl;
        Key number = keyboard.key_hit();
        switch (number.ascii()) {
            case '1':
                clear_screen();
                cga_wrapping_test();
                break;
            case '2':
                clear_screen();
                keyboard_test();
                break;
            case '3':
                clear_screen();
                cga_stream_edge_case_test();
                break;
            case '4':
                clear_screen();
                cga_stream_manipulator_test();
                break;
            case '5':
                clear_screen();
                cga_stream_color_setting_test();
                break;
            case '6':
                clear_screen();
                o_stream_hello_w();
                break;
            default:
                cga << "Your input was " << number.ascii() << ", which is supported" << CGA_Stream::endl;
                break;
        }
        keyboard.key_hit();
    }
}
