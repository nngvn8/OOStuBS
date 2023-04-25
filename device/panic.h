/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

#include "../guard/gate.h"

/* INCLUDES */

class Panic : public Gate
/* Add your code here */ 
{
public:
	Panic (const Panic &copy) = delete; // prevent copying
	Panic () {}

    void trigger();
 
};

#endif
