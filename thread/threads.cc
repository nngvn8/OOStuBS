//
// Created by benedict on 06.06.23.
//
#include "threads.h"

void Thread1::action() {

        int timer = 0;
        while(true) {
            timer ++;
            if (timer == 4) {
                cga << "Thread 1 : kill Thread 3" <<CGA_Stream::endl;
                scheduler.kill(thread3);
            }
            else {
                cga << this->name << ' ' << CGA_Stream::endl;
            }
            int ctr = 100000000;
            while (ctr) {
                ctr--;
            }
            scheduler.resume();
        }
}

void Thread2::action() {
    int timer = 0;
    while (true) {
        timer++;
        if (timer == 2) {
            cga << "Thread 2: Thread2.exit .. after schedule not enqueued again" <<CGA_Stream::endl;
            scheduler.exit();
        }
        else {
            cga << this->name << ' ' << CGA_Stream::endl;
        }
        int ctr = 100000000;
        while (ctr) {
            ctr--;
        }
        scheduler.resume();
    }
}

void Thread3::action() {
    while (true) {
        cga << this->name << ' ' << CGA_Stream::endl;
        int ctr = 100000000;
        while (ctr) {
            ctr--;
        }
        scheduler.resume();
    }
}

void Thread4::action(){
    while(true) {
        cga << this->name << ' ' << CGA_Stream::endl;
        int ctr = 100000000;
        while (ctr) {
            ctr--;
        }
        scheduler.resume();
    }
}