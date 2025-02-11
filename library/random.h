/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               R A N D O M                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#ifndef __random_include__
#define __random_include__

class Random {

private:
	unsigned long r0, r1, r2, r3, r4, r5, r6;
	unsigned long multiplier, addend, ic_state;

public:
	// CONSTRUCTOR: Initializes the RNG
	Random(int seed);
	Random(const Random &copy) = delete; // prevent copying

	// NUMBER: Returns a random number
	int number();
};

#endif
