/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The "bell ringer" (Bellringer) is activated periodically and checks if    */
/* any "bells" (Bell objects) need to ring. The bells are in a list that the */
/* bellringer manages.                                                       */
/*****************************************************************************/
#include "bellringer.h"
#include "../device/cgastr.h"
#include "../object/o_stream.h"


void Bellringer::check (){
    Chain* iterator;
    iterator = this->head;
    while(iterator){
        Bell* activated_iterator = (Bell*)iterator;
        activated_iterator->tick();
        if(activated_iterator->run_down()) {
            //cga << "A process had to jingle its bells" << CGA_Stream::endl;
            activated_iterator->ring();
        }
        iterator = iterator->next;
    }
}
void Bellringer::job (Bell *bell, int ticks){
        bell->wait(ticks);
        this->insert_first((Chain*)bell);
}
void Bellringer::cancel (Bell *bell){
    this->remove((Chain*)bell);
}
