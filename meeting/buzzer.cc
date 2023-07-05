/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* An "alarm clock" is a synchronization object that allows one or more      */
/* threads to put themselves to sleep for a specified time.                  */
/*****************************************************************************/

#include "buzzer.h"
#include "../device/watch.h"
#include "bellringer.h"
#include "../thread/customer.h"
#include "../thread/entrant.h"
#include "../syscall/guarded_organizer.h"
#include "../thread/threads.h"

Buzzer::Buzzer() {
    this->internal_counter = 0;
}

Buzzer::~Buzzer(){
    bellringer.cancel(this);
}
void Buzzer::set(int ms){
    //interval < ms in the normal case!
    int watch_interval_ms = watch.interval()/1000;
    int factor = ms/watch_interval_ms;
    bellringer.job((Bell*) this, factor);

}
void Buzzer::sleep (){
    Customer* active_customer = (Customer*)(Entrant*)guarded_organizer.Dispatcher::active();
//    cga << "Active customer" << ((UserThread*)active_customer)->name << CGA_Stream::endl;
    guarded_organizer.block(*active_customer, *this);
}

void Buzzer::ring() {
    while (Queue::head) {
        guarded_organizer.wakeup(*(Customer*)head);
        Queue::dequeue();
    }
}