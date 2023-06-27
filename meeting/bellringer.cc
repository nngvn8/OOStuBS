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
#include "bellringer.h";

void Bellringer::check () {
//    Bell bell = *(Bell*)head;
//    job((Bell*)head, 0);
}

void Bellringer::job(Bell* bell, int ticks) {
    insert_first(bell);
    bell->wait(ticks);
}

void Bellringer::cancel(Bell* bell) {
    remove(bell);
}