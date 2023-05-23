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
    int selected_nr_system = DEC_NR_SYS;

    /**
     * Converts a given number to a different base and inserts into string
     * @param os given o_stream
     * @param abs_number given number to insert, now the absolute value
     * @param is_negative whether the nr was negative before
     * @param bit_length_nr only important if nr_sys = 2 and its a negative number: important for 2 complement, determines the number of stuffed 1s
     * @return new O_Stream object
     */
    O_Stream& convert_long_to_list(O_Stream& os, unsigned long abs_number, bool is_negative,  int bit_length_nr);

    /**
     * Insets a given array of digits into the string as two's complement
     * @param os given O_stream
     * @param array__of_digits given array, still reversed ({1,0,0,0,0,1,0,1, ....} would represent the nr 10100001)
     * @param bit_length_nr nr of bits (short : 16, int : 32 , long : 64)
     * @param ctr length of given nr
     */
    void t2er_complement(O_Stream& os, char* array__of_digits, int bit_length_nr, int ctr);

public:
    O_Stream(){}

    /// Shifting data into buffer
    O_Stream& operator<< (char c);
    O_Stream& operator<< (unsigned char c);
    O_Stream& operator<< (unsigned short number);
    O_Stream& operator<< (short number);
    O_Stream& operator<< (unsigned int number);
    O_Stream& operator<< (int number);
    O_Stream& operator<< (unsigned long number);
    O_Stream& operator<< (long number);
    O_Stream& operator<< (void* ptr);
    O_Stream& operator<< (char* pointer);

    /// Shifting manipulators
    O_Stream& operator<< (O_Stream& (*fkt) (O_Stream&));
    static O_Stream& endl (O_Stream& os);
    static O_Stream& bin (O_Stream& os);
    static O_Stream& oct (O_Stream& os);
    static O_Stream& dec (O_Stream& os);
    static O_Stream& hex (O_Stream& os);
    static O_Stream& inst_print (O_Stream& os);
};

#endif