//
// Created by martin on 4/13/23.
//
#include "machine/keyctrl.h"
#include "device/cgastr.h"

unsigned char user_answer(Keyboard_Controller &contrlr, CGA_Stream &cga, char* user_input) {
    cga << user_input << CGA_Stream::endl;
    unsigned char key_content = contrlr.key_hit().ascii();
    cga << key_content << CGA_Stream::endl;
    return key_content;
}

void set_led_test(Keyboard_Controller &contrlr, CGA_Stream &cga) {
    unsigned char key_content;
    bool valid_input = false;

    while (true) {

        cga << "Select a LED! (caps_lock (4), num_lock (2), scroll_lock(1)) (Press q to quit)" << CGA_Stream::endl;
        while (!valid_input) {
            key_content = contrlr.key_hit().ascii();
            if (key_content == 'q') break;
            cga << key_content << CGA_Stream::endl;
            switch (key_content) {
                case '1':
                case '2':
                case '4': valid_input = true; break;
                default:
                    cga << "Type '4', '2' or '1' to select the corresponding LED!" << CGA_Stream::endl;
            }

        }
        if (key_content == 'q') break;

        valid_input = false;
        char led = (char) (key_content - 48);

        cga << "Select Mode! (on (1), off(0)) (Press q to quit)" << CGA_Stream::endl;

        while (!valid_input) {
            key_content = contrlr.key_hit().ascii();
            if (key_content == 'q') break;
            cga << key_content << CGA_Stream::endl;
            switch (key_content) {
                case '0':
                case '1': valid_input = true; break;
                default:
                    cga << "Type '1' or '0' to choose if the LED is on or off!" << CGA_Stream::endl;
            }
        }
        if (key_content == 'q') break;

        valid_input = false;
        bool on = (bool) (key_content - 48);

        contrlr.set_led(led, on);
    }
    cga << "You left the LED test!" << CGA_Stream::endl;
}

void set_repeat_rate_test(Keyboard_Controller& contrlr, CGA_Stream& cga) {
    unsigned char key_content;
    bool valid_input = false;
    int speed;
    int delay;

    while (true) {

        cga << "Select a repeat rate! (integer 1 - 7 (low to high)) (Press q to quit)" << CGA_Stream::endl;
        while (!valid_input) {
            key_content = contrlr.key_hit().ascii();
            if (key_content == 'q') break;
            cga << key_content << CGA_Stream::endl;
            switch (key_content) {
                case '1': speed = 0x14; valid_input = true; break;
                case '2': speed = 0x10; valid_input = true; break;
                case '3': speed = 0x0c; valid_input = true; break;
                case '4': speed = 0x08; valid_input = true; break;
                case '5': speed = 0x04; valid_input = true; break;
                case '6': speed = 0x02; valid_input = true; break;
                case '7': speed = 0x00; valid_input = true; break;

                default:
                    cga << "Type an integer between 1 and 7 to select the corresponding repeat rate! (Press q to quit)" << CGA_Stream::endl;
            }

        }
        if (key_content == 'q') break;

        valid_input = false;
        cga << CGA_Stream::hex << "Selected repeat rate: " << speed << CGA_Stream::endl;
        cga << "Select delay! (integer 1 - 4 (low to high)) (Press q to quit)" << CGA_Stream::endl;
        while (!valid_input) {
            key_content = contrlr.key_hit().ascii();
            if (key_content == 'q') break;
            cga << key_content << CGA_Stream::endl;
            switch (key_content) {
                case '1': delay = 0x00; valid_input = true; break;
                case '2': delay = 0x01; valid_input = true; break;
                case '3': delay = 0x02; valid_input = true; break;
                case '4': delay = 0x03; valid_input = true; break;
                default:
                    cga << "Type an integer between 1 and 4 to select the corresponding delay! (Press q to quit)" << CGA_Stream::endl;
            }
        }
        if (key_content == 'q') break;

        valid_input = false;
        cga << CGA_Stream::hex << "Selected delay: " << delay << CGA_Stream::endl;

        contrlr.set_repeat_rate(speed, delay);

        cga << "Type freely to test repeat rate and delay! (press q to quit free typing)" <<  CGA_Stream::endl;
        while (key_content != 'q') {
            key_content = contrlr.key_hit().ascii();
            cga << key_content << CGA_Stream::endl;
        }

    }
    cga << "You left the repeat rate test!" << CGA_Stream::endl;
}

void keyboard_test() {
    Keyboard_Controller contrlr =  Keyboard_Controller();
    CGA_Stream cga = CGA_Stream();
    unsigned char key_content = '0';

    while (key_content != 'q') {
        cga << "What do you want to test? (Press q to quit)" << CGA_Stream::endl
            << "(1) LED Test" << CGA_Stream::endl
            << "(2) delay-speed test" << CGA_Stream::endl;
        key_content = contrlr.key_hit().ascii();
        if (key_content == 'q') break;
        cga << key_content << CGA_Stream::endl;
        switch (key_content){
            case '1':
                set_led_test(contrlr, cga);
                break;
            case '2':
                set_repeat_rate_test(contrlr, cga);
                break;
            default:
                cga << "No valid option!" << CGA_Stream::endl;
        }
    }

    cga << "You left \"keyboard test\"!" << CGA_Stream::endl;
}

void classic_key_board_test(){
    Keyboard_Controller contrlr =  Keyboard_Controller();
    CGA_Stream cga = CGA_Stream();
    cga << "Test the classic keyboard (Press q to quit)" << CGA_Stream::endl;
    unsigned char key_content = '0';

    while (key_content != 'q') {
        key_content = contrlr.key_hit().ascii();
        if (key_content == 'q') break;
        if (key_content == 13 ) cga<<CGA_Stream::endl;
        cga << key_content << CGA_Stream::inst_print ;
        }
    }



