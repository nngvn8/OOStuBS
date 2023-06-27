/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             T H R E A D                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements user interface of a thread.                                    */
/*****************************************************************************/

#ifndef __thread_include__
#define __thread_include__

#include "../thread/customer.h"


class Thread: public Customer {
public:
    using Customer::Customer;
	Thread(const Thread &copy) = delete; // prevent copying
/* Add your code here */ 
 
};

#endif
