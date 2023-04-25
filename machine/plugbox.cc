/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstracts an interrupt vector table. Allows to configure handler routines */
/* for every hardware and software interrupt and every CPU exception.        */
/*****************************************************************************/
#include "plugbox.h"
#include "../device/panic.h"

Plugbox::Plugbox() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        interrupt_vector_table[i] = &global_panic;
    }
}

void Plugbox::assign(unsigned int slot, Gate& gate) {
    if (slot >= TABLE_SIZE) {
        // add error message when possible
        return;
    }

    interrupt_vector_table[slot] = &gate;
}


Gate& Plugbox::report(unsigned int slot) {
    if (slot >= TABLE_SIZE) {
        // add error message when possible
    }

    return *interrupt_vector_table[slot];
}
