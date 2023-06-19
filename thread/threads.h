//
// Created by benedict on 06.06.23.
//

#ifndef OOSTUBBS_MBJ_THREADS_H
#define OOSTUBBS_MBJ_THREADS_H


#include "../user/appl.h"
#include "scheduler.h"
#include "../object/o_stream.h"
#include "../device/cgastr.h"



class Thread1 : public Application {
private:
    char* name = "Thread1";
    int wait_timer;

public:
    Thread1(void* tos, int wait_timer): Application(tos){
        this->wait_timer = wait_timer;
    }
    void action();

};

class Thread2: public Application {
private:
    char* name = "Thread2";
    int wait_timer;

public:
    Thread2(void* tos, int wait_timer): Application(tos){
        this->wait_timer = wait_timer;
    }
    void action();
};

class Thread3: public Application {
private:
    char* name = "Thread3";
    int wait_timer;

public:
    Thread3(void* tos, int wait_timer): Application(tos){
        this->wait_timer = wait_timer;
    }
    void action();
};

class Thread4: public Application {
private:
    int wait_timer;
    char* name = "Thread4";


public:
    Thread4(void* tos, int wait_timer): Application(tos){
        this->wait_timer = wait_timer;
    }
    void action();
};

extern Thread1 thread1;
extern Thread2 thread2;
extern Thread3 thread3;
extern Thread4 thread4;



#endif //OOSTUBBS_MBJ_THREADS_H
