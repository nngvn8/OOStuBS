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

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "../guard/gate.h"
#include "../device/panic.h"

#define TABLE_SIZE 64

class Plugbox {
public:
	const int timer = 32;
    const int keyboard = 33;

    Plugbox();
    Plugbox(const Plugbox &copy) = delete; // prevent copying
    void assign(unsigned int slot, Gate& gate);
    Gate& report(unsigned int slot);
private:
    Gate global_panic = Panic("Error: Gate not initialized!");
    Gate interrupt_vector_table[TABLE_SIZE];
};

#endif
