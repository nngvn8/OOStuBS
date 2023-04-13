#ifndef O_STREAM_OSTREAM_H
#define O_STREAM_OSTREAM_H


#include <list>
#include "strbuf.h"

#define BIN_NR_SYS 2
#define OCT_NR_SYS 8
#define DEC_NR_SYS 10
#define HEX_NR_SYS 16


class O_Stream : public Stringbuffer {
private:
public:
    O_Stream(){}
    int selected_nr_system = DEC_NR_SYS;
    O_Stream& operator<<(char c);
    O_Stream& operator<< (unsigned char c);
    O_Stream& operator<< (unsigned short number);
    O_Stream& operator<< (short number);
    O_Stream& operator<< (unsigned int number);
    O_Stream& operator<< (int number);
    O_Stream& operator<< (unsigned long number);
    O_Stream& operator<< (long number);
    O_Stream& operator<< (char* text);
    O_Stream& operator<< (void* pointer);

    O_Stream& operator<< (O_Stream& (*fkt) (O_Stream&));

    static O_Stream& endl (O_Stream& os);

    static O_Stream& bin (O_Stream& os);

    static O_Stream& oct (O_Stream& os);

    static O_Stream& dec (O_Stream& os);

    static O_Stream& hex (O_Stream& os);


};

O_Stream& convert_long_to_list(O_Stream& os, unsigned long abs_number, int selected_nr_system, bool is_negative);

#endif


