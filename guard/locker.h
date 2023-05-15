/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Locker class implements a lock that can be used to protect critical   */
/* sections. However, the variable only indicates whether the critical       */
/* section is free. Potentially necessary waiting, and protection for        */
/* counting functionality, must be implemented elsewhere.                    */
/*****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__

class Locker {
private:
    bool available = true;

public:
	Locker(const Locker &copy) = delete; // prevent copying
    void enter() {
        if (!available) {cga << "enter called although already not \"available\"" << CGA_Stream::endl;}
        available = false;
    };
    void retne() {
        if (available) {cga << "retne called although already \"available\"" << CGA_Stream::endl;}
        available = true;
    };
    bool avail() {
        return available;
    };

};

#endif
