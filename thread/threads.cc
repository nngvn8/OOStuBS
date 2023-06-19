//
// Created by benedict on 06.06.23.
//
#include "threads.h"
#include "../syscall/guarded_scheduler.h"
#include "../guard/guard.h"
#include "../machine/cpu.h"

void Thread1::action() {


    while(true) {

        cga << this->name << ' '<< CGA_Stream::endl;
        int ctr = 5000000;
        while (ctr) {
            ctr--;
        }
            //guarded_scheduler.resume();
        }
}

void Thread2::action() {

    while(true) {
        cga.clear_screen();
        //cga << CGA_Stream::inst_print;
        //cga << "Das was oben ist war noch im Buffer" << CGA_Stream::endl;
        cga << this->name << ' ' << CGA_Stream::endl;
        int ctr = this->wait_timer;
        while (ctr) {
            ctr--;
        }
        guarded_scheduler.resume();
    }
}

void Thread3::action() {

    while(true) {
        cga << this->name << ' ' << CGA_Stream::endl;
        int ctr = this->wait_timer;
        /*while (ctr) {
            ctr--;
        }*/
        //guarded_scheduler.resume();
    }
}

void Thread4::action(){

    while(true) {
        cga << this->name << ' ' << CGA_Stream::endl;
        int ctr = this->wait_timer;
        /*while (ctr) {
            ctr--;
        }*/
        //guarded_scheduler.resume();
    }
}