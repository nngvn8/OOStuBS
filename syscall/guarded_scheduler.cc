/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements the system-call interface to the Scheduler.                    */
/*****************************************************************************/
#include "guarded_scheduler.h"
#include "thread.h"
#include "../guard/secure.h"

void Guarded_Scheduler::ready (Thread& that){
    Thread* t_ptr = &that;
    {Secure section;
        this->Scheduler::ready (*(Entrant*)(t_ptr));
    }
}
void Guarded_Scheduler::exit (){
    {Secure section;
        this->Scheduler::exit();

    }
}
void Guarded_Scheduler::kill (Thread& that){
    Thread* t_ptr = &that;
    {Secure section;
        this->Scheduler::kill(*(Entrant*)(t_ptr));

    }
}
void Guarded_Scheduler::resume (){
    {Secure section;
        this->Scheduler::resume();
    }
}
