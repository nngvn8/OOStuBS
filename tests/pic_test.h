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
    cga << "Slave PIC \n";
    for(int i = 0; i < 16; i++){
        cga <<"(";
        //inserts a 0 before every single digit number for readability
        if(i <= 9)cga << '0';
        //insterts the rest
        cga << i  << ": "<<pic.is_masked(i) << ")";
        //make break line for better readability
        if(i == 7) cga << "\nMaster PIC \n";
    }
    cga << O_Stream::endl;

}


void pic_allow_forbid_is_masked_test(){
    CGA_Stream cga = CGA_Stream();
    PIC pic = PIC();
    //TODO THIS IS WEIRD can someone explain why it is not printing those statements, but only one? -> cant continue testing
    cga << "Starting the PIC test: \n" << O_Stream::endl;
    cga << "Initially reading which lines are disabled: \n" << O_Stream::endl;
    //print_curr_state_pic_irqs_line_by_line(pic, cga);
    print_curr_state_pic_irqs_in_one_row(pic, cga);

    //should not change anythin
    cga << "\nAllowing 0:" << O_Stream::endl;
    pic.allow(0);
    print_curr_state_pic_irqs_in_one_row(pic, cga);

    cga << "\nForbidding 0 and 1:" << O_Stream::endl;
    pic.forbid(0);
    pic.forbid(1);
    print_curr_state_pic_irqs_in_one_row(pic, cga);

    cga << "\nReallowing 0 and 1:" << O_Stream::endl;
    pic.allow(0);
    pic.allow(1);
    print_curr_state_pic_irqs_in_one_row(pic, cga);

    //now the entire master pic
    cga << "\nForbidding the master, Shall the slave reign:" << O_Stream::endl;
    for(int i = 8; i <= 15; i++) pic.forbid(i);
    print_curr_state_pic_irqs_in_one_row(pic, cga);

    //huh? no such thing as a 16th line
    pic.allow(16);
    print_curr_state_pic_irqs_in_one_row(pic, cga);







}




#endif //OOSTUBBS_MBJ_PIC_TEST_H
