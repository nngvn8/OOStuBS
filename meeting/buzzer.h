/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* An "alarm clock" is a synchronization object that allows one or more      */
/* threads to put themselves to sleep for a specified time.                  */
/*****************************************************************************/

#ifndef __Buzzer_include__
#define __Buzzer_include__

#include "waitingroom.h"
#include "bell.h"

/* Add your code here */

class Buzzer: public Waitingroom, Bell
{
private:
public:
	Buzzer(const Buzzer &copy) = delete; // prevent copying
    Buzzer ();
    virtual ~Buzzer();
    virtual void ring();
    void set (int ms);
    void sleep ();
};

#endif
