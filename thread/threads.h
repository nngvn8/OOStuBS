//
// Created by benedict on 06.06.23.
//

#ifndef OOSTUBBS_MBJ_THREADS_H
#define OOSTUBBS_MBJ_THREADS_H


#include "../user/appl.h"
#include "scheduler.h"
#include "../object/o_stream.h"
#include "../device/cgastr.h"



class UserThread : public Application {
private:
    void (*action_pointer) (UserThread*) ;
public:
    int wait_timer;
    char* name;
    char* msg;

    UserThread(void* tos, int wait_timer, char* name, char* msg, void (*action_pointer) (UserThread*) ) :
        Application(tos), wait_timer(wait_timer), name(name), msg(msg) {
        this->action_pointer = action_pointer;
    }

    void action(){
        while (true) {
            action_pointer(this);
            for (int i = 0; i < wait_timer; i++);
        }
    }

    char* getName() { return name; };

    char* getMsg() { return msg; };
};

#endif //OOSTUBBS_MBJ_THREADS_H
