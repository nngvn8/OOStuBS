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

#include "pic.h"

PIC::PIC() : slave_port_A(SLAVE_PORT_A), slave_port_B(SLAVE_PORT_B),
             master_port_A(MASTER_PORT_A),master_port_B(MASTER_PORT_B){
}

void PIC::forbid(int interrupt_device){
    int current_state_pic_IMR;
    //write to slave cuz 0-7 are connected to the slave
    if(interrupt_device >= 0 && interrupt_device <= 7){
        current_state_pic_IMR = slave_port_B.inb();
        current_state_pic_IMR |= (1 << interrupt_device);
        slave_port_B.outb(current_state_pic_IMR);
    }
        //write to master cuz 8-15 are connected to the master
    else if(interrupt_device >= 8 && interrupt_device <= 15){
        current_state_pic_IMR = master_port_B.inb();
        interrupt_device -= 8;
        current_state_pic_IMR |= (1 << interrupt_device);
        master_port_B.outb(current_state_pic_IMR);
    }
    //do nothing, TODO error?
    else return;
}

void PIC::allow(int interrupt_device){
    int current_state_pic_IMR;
    //wirte to slave cuz 0-7 are connected to the slave
    if(interrupt_device >= 0 && interrupt_device <= 7){
        current_state_pic_IMR = slave_port_B.inb();
        current_state_pic_IMR &= ~(1 << interrupt_device);
        slave_port_B.outb(current_state_pic_IMR);
    }
    //write ti master cuz 8-15 are connected to the master
    else if(interrupt_device >= 8 && interrupt_device <= 15){
        current_state_pic_IMR = master_port_B.inb();
        interrupt_device -= 8;
        current_state_pic_IMR &= ~(1 << interrupt_device);
        master_port_B.outb(current_state_pic_IMR);
    }
    //do nothing, TODO error?
    else return;
}

// if interrupts are not forwarded: return true
bool PIC::is_masked(int interrupt_device){
    int current_state_pic_IMR;
    //ask slave cuz 0-7 are connected to the slave
    if(interrupt_device >= 0 && interrupt_device <= 7){
        current_state_pic_IMR = slave_port_B.inb();
    }
    //ask master cuz 8-15 are connected to the master
    else if(interrupt_device >= 8 && interrupt_device <= 15){
        current_state_pic_IMR = master_port_B.inb();
        interrupt_device -= 8;
    }
    //error case
    else{
        //TODO error case, print of write into log
        return false;
    }
    //check whether the bit is set
    return (current_state_pic_IMR & (1 << interrupt_device));
}