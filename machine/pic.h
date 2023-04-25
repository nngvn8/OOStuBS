/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* By using the PIC, hardware interrupts can be enabled or suppressed        */
/* individually. This way we can control whether interrupts of a specific    */
/* device are forwarded to the CPU at all. Even then, the interrupt handler  */
/* gets only activated if the CPU is ready to react to interrupts. This can  */
/* be controlled by using class CPU.                                         */
/*****************************************************************************/

#ifndef __pic_include__
#define __pic_include__
#include "io_port.h"

#define SLAVE_PORT_A 0x20
#define SLAVE_PORT_B 0x21
#define MASTER_PORT_A 0xa0
#define MASTER_PORT_B 0xa1

enum {
    timer    = 0,
    keyboard = 1
};


class PIC {
private:
    const IO_Port slave_port_A;
    const IO_Port slave_port_B;
    const IO_Port master_port_A;
    const IO_Port master_port_B;

public:
    PIC();
	PIC(const PIC &copy) = delete; // prevent copying

    /**
     * Configure the PIC so that it forwards interrupts for the device
     * with number interrupt_device to the cpu
     * @param interrupt_device
     */
    void allow (int interrupt_device);

    /**
     * Configure the PIC so that is surprises a specific hardware interrupt of the device number (interrupt device)
     * @param interrupt_device
     */
    void forbid (int interrupt_device);

    /**
     * Determine the current state of teh masking bit of a specific hardware interrupt with interrupt number interrupt_device.
     * If interrupts of this device are not forwarded to the cpu, return true, otherwise return false
     * @param interrupt_device
     * @return
     */
    bool is_masked (int interrupt_device);
};

#endif
