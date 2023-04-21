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
/**
 * OCW is simply a placeholder for the disabled-interrupts mask, beeing directly transferred
 * into the interrupt mask register, set bit X ensures that interrupt X is disabled
 * @param interrupt_device nr between 0 and 16
 */
void PIC::allow(int interrupt_device){

    int current_state_pic_IMR;
    //wirte to slave cuz 0-7 are connected to the slave
    if(interrupt_device >= 0 && interrupt_device <= 7){
        current_state_pic_IMR = slave_port_B.inb();
        current_state_pic_IMR |= convert_to_one_hot(interrupt_device);
        slave_port_B.outb(current_state_pic_IMR);
    }
        //write ti master cuz 8-15 are connected to the master
    else if(interrupt_device >= 8 && interrupt_device <= 15){
        current_state_pic_IMR = master_port_B.inb();
        interrupt_device -= 8;
        current_state_pic_IMR |= convert_to_one_hot(interrupt_device);
        master_port_B.outb(current_state_pic_IMR);
    }

}




void PIC::forbid(int interrupt_device){

    int current_state_pic_IMR;
    //wirte to slave cuz 0-7 are connected to the slave
    if(interrupt_device >= 0 && interrupt_device <= 7){
        current_state_pic_IMR = slave_port_B.inb();
        current_state_pic_IMR &= ~convert_to_one_hot(interrupt_device);
        slave_port_B.outb(current_state_pic_IMR);
    }
    //write ti master cuz 8-15 are connected to the master
    else if(interrupt_device >= 8 && interrupt_device <= 15){
        current_state_pic_IMR = master_port_B.inb();
        interrupt_device -= 8;
        current_state_pic_IMR &= ~convert_to_one_hot(interrupt_device);
        master_port_B.outb(current_state_pic_IMR);
    }

}



//if interrupts are not forwarded: return true
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
    //check wheter the bit is set
    if(current_state_pic_IMR & (convert_to_one_hot(interrupt_device))) return true;
    else return false;
}
//TODO besser doch int ?
char PIC::convert_to_one_hot(int x){
    switch(x){
        case 0:return 0b1;
        case 1:return 0b10;
        case 2:return 0b100;
        case 3:return 0b1000;
        case 4:return 0b10000;
        case 5:return 0b100000;
        case 6:return 0b1000000;
        case 7:return 0b10000000;
        default:
            //TODO error print or error log
            return 0b0;
    }
}
