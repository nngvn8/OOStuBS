/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        G U A R D E D _ B U Z Z E R                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Guarded_Buzzer class implements the system call interface to the      */
/* Buzzer class.                                                             */
/*****************************************************************************/

/* INCLUDES */

#include "../guard/secure.h"
#include "guarded_buzzer.h"

Guarded_Buzzer::~Guarded_Buzzer(){
    Secure section;
    this->Buzzer::~Buzzer();
}
void Guarded_Buzzer::set (int ms){
    Secure section;
    this->Buzzer::set(ms);
}
void Guarded_Buzzer::sleep (){
    Secure section;
    this->Buzzer::sleep();
//    cga << "done with sleep" << CGA_Stream::endl;
}
