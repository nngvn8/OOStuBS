//
// Created by benedict on 01.07.23.
//

#ifndef OOSTUBBS_MBJ_BELLRINGER_TEST_H
#define OOSTUBBS_MBJ_BELLRINGER_TEST_H

#include "meeting/bellringer.h"

static void bellringer_test() {

    guard.leave();

    Bell bell1;
    Bell bell2;
    Bell bell3;


    bellringer.job((Bell*) &bell1 , 1);
    bellringer.job((Bell*) &bell2 , 2);
    bellringer.job((Bell*) &bell3 , 3);

    cga << "We finished jobbing" << CGA_Stream::endl;
    while (1){
       }
}

#endif //OOSTUBBS_MBJ_BELLRINGER_TEST_H
