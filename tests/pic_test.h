//
// Created by benedict on 21.04.23.
//

#ifndef OOSTUBBS_MBJ_PIC_TEST_H
#define OOSTUBBS_MBJ_PIC_TEST_H

#include "device/cgastr.h"
#include "machine/pic.h"

void print_curr_state_pic_irqs_line_by_line(PIC& pic, CGA_Stream& cga){
    for(int i = 0; i < 16; i++){
        cga << "Line: " << i << ", enbaled? : " << pic.is_masked(i) << O_Stream::endl;
    }

}
void print_curr_state_pic_irqs_in_one_row(PIC& pic, CGA_Stream& cga){
    cga << "This is the current line: \n" << O_Stream::endl;
    for(int i = 0; i < 16; i++){
        cga <<"("<< i  << pic.is_masked(i) << ", )";
    }
    cga << O_Stream::endl;

}


void pic_allow_forbid_is_masked_test(){
    CGA_Stream cga = CGA_Stream();
    PIC pic = PIC();
    //TODO THIS IS WEIRD can someone explain why it is not printing those statements, but only one? -> cant continue testing
    cga << "Starting the PIC test: \n" << O_Stream::endl;
    cga << "Initially reading which lines are disabled: \n" << O_Stream::endl;
    cga << "Initially reading which lines are disabled: \n" << O_Stream::endl;
    cga << "Initially reading which lines are disabled: \n" << O_Stream::endl;
    cga << "Initially reading which lines are disabled: \n" << O_Stream::endl;


    //print_curr_state_pic_irqs_line_by_line(pic, cga);
    //print_curr_state_pic_irqs_in_one_row(pic, cga);

}




#endif //OOSTUBBS_MBJ_PIC_TEST_H
