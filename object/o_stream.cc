/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The O_Stream class defines the << operator for several pre-defined data   */
/* types and thereby realizes output functionality similar to C++'s iostream */
/* library. By default, this class supports printing characters, strings and */
/* integer numbers of various bit sizes. Another << operator allows to use   */
/* so-called 'manipulators'.                                                 */
/*                                                                           */
/* Besides class O_Stream this file also defines the manipulators hex, dec,  */
/* oct and bin for choosing the basis in number representations, and endl    */
/* for implementing an (implicitly flushing) line termination.               */
/*****************************************************************************/

#include "object/o_stream.h"
#include <list>

void O_Stream::flush() {
    //TODO print it to the console
    //clear string necessary? i dont think so
    this->index = 0;
}

O_Stream& O_Stream::operator<<(const char c){
    this->put(c);
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned char u_c){
    this->put(u_c);
    return *this;
}


O_Stream& O_Stream::operator<< (unsigned short number) {
    return convert_long_to_list(*this, number);
}
O_Stream& O_Stream::operator<< (short number) {
    return convert_long_to_list(*this, number);
}
O_Stream& O_Stream::operator<< (unsigned int number) {
    return convert_long_to_list(*this, number);
}
O_Stream& O_Stream::operator<< (int number) {
    return convert_long_to_list(*this, number);
}

O_Stream& O_Stream::operator<< (long number){
    return convert_long_to_list(*this, number);
}


//pointer arithmetic :D for strings
O_Stream& O_Stream::operator<< (char* pointer){
    while (*pointer != '\0'){
        this->put(*pointer);
        pointer += 1;
    }
    return *this;
}




//TODO unsigned long, is ez, but increases code size by copying some code
//TODO void pointer


//makes o_stream accept endl for example
O_Stream& O_Stream::operator<< (O_Stream& (*fkt) (O_Stream&)){
    (*fkt)(*(O_Stream *)this);
    return (*this);
}

//inserts a line break
O_Stream& O_Stream::endl(O_Stream& os)  {
    return os << 'e'<<'n'<<'d'<<'l';
}
//selects the binary number system
O_Stream& O_Stream::bin(O_Stream& os)  {
    os.selected_nr_system = BIN_NR_SYS;
    return os << 'b'<<'i'<<'n';
}


//selects the binary number system
O_Stream& O_Stream::oct(O_Stream& os)  {
    os.selected_nr_system = OCT_NR_SYS;
    return os << 'o'<<'c'<<'t';
}

//selects the decimal number system
O_Stream& O_Stream::dec(O_Stream& os)  {
    os.selected_nr_system = DEC_NR_SYS;

    return os << 'd'<<'e'<<'c';
}

//selects the hexadecimal number system
O_Stream& O_Stream::hex(O_Stream& os)  {
    os.selected_nr_system = HEX_NR_SYS;

    return os << 'h'<<'e'<<'x';
}







O_Stream& convert_long_to_list(O_Stream& os, long i){

    bool is_negative = false;

    if (i < 0){
        is_negative = true;
        i *= (-1);
    }

    std::list<char> char_list;
    //val to compute modula with
    long mod_ctr = 10;
    int char_to_append;

    //calc modulo and then multiply mod_ctr and subtract!
    while(i != 0){
        char_to_append = i % mod_ctr;
        i = i-char_to_append;
        char_to_append = char_to_append / (mod_ctr/10);
        //0..9 starts at 48 with the 0
        char_list.push_front(char_to_append + 48);
        mod_ctr = mod_ctr * 10;
    }

    // '-' is the 45 in the ascii table
    if(is_negative) char_list.push_front(45);
    //char list is reversed since we use push front
    //for elem in char list: put it in the stringbuffer

    for(const auto& ch : char_list){
        os.put(ch);
    }
    return os;

}

/* Add your code here */ 
