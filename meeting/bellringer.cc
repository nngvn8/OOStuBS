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

void Bellringer::check () {
/// recursive version that probably is not in O(1) either
//    if (head) {
//        ((Bell*)head)->ring_and_next();
//    }
/// O(n) variant
    Chain* cur_bell = head; // always casted on Bell because Bell is abstract
    while (cur_bell) {
        ((Bell*)cur_bell)->ring();
        cur_bell = cur_bell->next;
    }
}

void Bellringer::job(Bell* bell, int ticks) {
    bell->wait(ticks);
    insert_first(bell);
}

void Bellringer::cancel(Bell* bell) {
    remove(bell);
}