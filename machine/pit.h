/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

class PIT {
public:
	PIT(const PIT &copy) = delete; // prevent copying


private:
    int _us;

public:
    /**
     * Initialised in such a way that it regularly triggers interrupts at intervals of approx. us microseconds.
     * @warning The resolution of the timer component is a maximum of 838 nanoseconds.
     * @warning Clamps to given value to between 0 and 54925
     * @param us number of microseconds
     */
	PIT(int us) {
		interval (us);
	}

    /**
     * Indicates which interrupt interval was set.
     * @return number of microseconds
     */
	int interval() {
        return _us;
	}

    /**
     * Sets a new interrupt interval.
     * @param us number of microseconds
     */
	void interval(int us);
};

#endif
