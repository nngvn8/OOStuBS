//
// Created by benedict on 06.06.23.
//

#ifndef OOSTUBBS_MBJ_THREADS_H
#define OOSTUBBS_MBJ_THREADS_H


#include "../user/appl.h"
#include "scheduler.h"
#include "../object/o_stream.h"
#include "../device/cgastr.h"



class Thread : public Application {
private:
    char* name;
    int wait_timer;
    void* action_pointer(*Thread);

public:
    Thread(void* tos, int wait_timer, char* name, void* action_pointer) :
        Application(tos), wait_timer(wait_timer), name(name), action_pointer(action_pointer){}

    void action(){
        action_pointer(this);
    }
};

#endif //OOSTUBBS_MBJ_THREADS_H
