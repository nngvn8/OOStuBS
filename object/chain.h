/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              C H A I N                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* By inheriting from the Chain class, the derived class inherits a chain    */
/* pointer that allows its instances to be enqueued in a linked list         */
/* (implemented in the Queue class).                                         */
/*****************************************************************************/

#ifndef __chain_include__
#define __chain_include__

class Chain {

public:
    Chain() {}
    Chain(const Chain &copy) = delete; // prevent copying
	Chain *next = 0;
};

#endif
