/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#include "pit.h"
#include "io_port.h"

#define F 1.19318
#define MAX_US 54925
#define PIT1_CONTROL_REG 0x43
#define PIT1_COUNTER0 0x40

void PIT::interval(int us){
    // Check size of us value (just clamping, no error)
    if (us > MAX_US) {
        us = MAX_US;
    }
    if (us < 0) {
        us = 0;
    }
    _us = us;  // for returning the current value later

    // Converting us to PIT number
    /* Explanation
     * It takes f = 1.19318 MHz per decrease
     * us = 10^-6, and M = 10^6 => directly convertable
     * Number = us * f (because us * MHz = 1)
     * Max number is 2^16, meaning a maximum us value of 2^16/f = 54_925.4932197992us ~= 54_925
     */
    int pit_number = us * F;

    // Take apart the us value
    char lsb = pit_number & 0xFF;
    char msb = (pit_number>>8) & 0xFF;

    // Setup PIT
    /* Explanation:
     * 00 for selecting counter 0
     * 11 for next sending the least significant and then most significant byte
     * 010 for selecting mode 2, which will count down, generate a pulse and reset to the start value
     * 0 for selecting 16-bits binary counting
     */
    char register_value = 0b00110100;
    IO_Port pit1_control_reg = IO_Port(PIT1_CONTROL_REG);
    pit1_control_reg.outb(register_value);

    // Send lsb and msb to PIT
    IO_Port pit1_counter0 = IO_Port(PIT1_COUNTER0);
    pit1_counter0.outb(lsb);
    pit1_counter0.outb(msb);
}
