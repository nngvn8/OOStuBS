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
    int wait_timer;
    void (*action_pointer) (UserThread*) ;
public:
    char* name;

    UserThread(void* tos, int wait_timer, char* name, void (*action_pointer) (UserThread*) ) :
        Application(tos), wait_timer(wait_timer), name(name) {
        this->action_pointer = action_pointer;
    }

    void action(){
        while (true) {
            action_pointer(this);
            for (int i = 0; i < wait_timer; i++);
        }
    }
};

#endif //OOSTUBBS_MBJ_THREADS_H
