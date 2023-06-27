/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C U S T O M E R                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Customer class extends the Entrant class with the ability to record   */
/* and retrieve an event that the process in question is waiting for.        */
/*****************************************************************************/

#ifndef __customer_include__
#define __customer_include__

#include "entrant.h"
class Customer : public Entrant {
public:
	Customer (const Customer &copy) = delete; // prevent copying
    using Entrant::Entrant;
private:
/* Add your code here */ 
};

#endif
