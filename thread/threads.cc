//
// Created by benedict on 06.06.23.
//
#include "threads.h"
#include "../syscall/guarded_scheduler.h"

void Thread1::action() {

        while(true) {
            cga << this->name << ' ' << CGA_Stream::endl;
            int ctr = this->wait_timer;
            while (ctr) {
                ctr--;
            }
            guarded_scheduler.resume();
        }
}

void Thread2::action() {

    while(true) {
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
        while (ctr) {
            ctr--;
        }
        guarded_scheduler.resume();
    }
}

void Thread4::action(){

    while(true) {
        cga << this->name << ' ' << CGA_Stream::endl;
        int ctr = this->wait_timer;
        while (ctr) {
            ctr--;
        }
        guarded_scheduler.resume();
    }
}