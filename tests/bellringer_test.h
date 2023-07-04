//
// Created by benedict on 01.07.23.
//

#ifndef OOSTUBBS_MBJ_BELLRINGER_TEST_H
#define OOSTUBBS_MBJ_BELLRINGER_TEST_H

#include "meeting/bellringer.h"
#include "meeting/buzzer.h"

static void bellringer_test() {
    cga << "We need to get rid of the brackets first in order to start the test" << CGA_Stream::endl;
    //Bell is an abstract class, don't forget that!

    guard.leave();

    Buzzer bell1;
    Buzzer bell2;
    Buzzer bell3;

    bellringer.job((Bell*) &bell1 , 1);
    bellringer.job((Bell*) &bell2 , 2);
    bellringer.job((Bell*) &bell3 , 3);

    cga << "We finished jobbing" << CGA_Stream::endl;

    while (1){
    }
}

#endif //OOSTUBBS_MBJ_BELLRINGER_TEST_H
