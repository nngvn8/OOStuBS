#include "o_stream.h"


O_Stream& O_Stream::operator<<(const char c){
    this->put(c);
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned char u_c){
    this->put(u_c);
    return *this;
}

O_Stream& O_Stream::operator<< (unsigned short number) {
    return convert_long_to_list(*this, (unsigned long)number, this->selected_nr_system, false );
}
O_Stream& O_Stream::operator<< (short number) {
    unsigned long abs_number = 0;
    number < 0 ? abs_number = -1*number : abs_number = (number) ;
    return convert_long_to_list(*this, abs_number, this->selected_nr_system, number < 0 );
}
O_Stream& O_Stream::operator<< (unsigned int number) {
    return convert_long_to_list(*this, (unsigned long)number, this->selected_nr_system, false);
}
O_Stream& O_Stream::operator<< (int number) {
    unsigned long abs_number = 0;
    number < 0 ? abs_number = -1*number : abs_number = (number) ;
    return convert_long_to_list(*this, abs_number, this->selected_nr_system, number < 0 );
}
O_Stream& O_Stream::operator<< (unsigned long number){
    return convert_long_to_list(*this, (unsigned long)number, this->selected_nr_system, false );
}

O_Stream& O_Stream::operator<< (long number){
    unsigned long abs_number = 0;
    number < 0 ? abs_number = -1*number : abs_number = (number) ;
    return convert_long_to_list(*this, abs_number, this->selected_nr_system, number < 0 );
}


O_Stream & O_Stream::operator<<(void * ptr) {
    auto address = (unsigned long) ptr;
    int tmp = this->selected_nr_system;
    this->selected_nr_system = HEX_NR_SYS;
    *this << address;

    this->selected_nr_system = tmp;
    return (*this);

}

//pointer arithmetic :D for strings
O_Stream& O_Stream::operator<< (char* pointer){
    while (*pointer != '\0'){
        this->put(*pointer);
        pointer += 1;
    }
    return *this;
}

//makes o_stream accept endl for example
O_Stream& O_Stream::operator<< (O_Stream& (*fkt) (O_Stream&)){
    (*fkt)(*(O_Stream *)this);
    return (*this);
}

//inserts a line break
O_Stream& O_Stream::endl(O_Stream& os)  {
    os.put('\n');
    os.flush();
    return os;
}
//selects the binary number system
O_Stream& O_Stream::bin(O_Stream& os)  {
    os.selected_nr_system = BIN_NR_SYS;
    return os;
}


//selects the binary number system
O_Stream& O_Stream::oct(O_Stream& os)  {
    os.selected_nr_system = OCT_NR_SYS;
    return os ;
}

//selects the decimal number system
O_Stream& O_Stream::dec(O_Stream& os)  {
    os.selected_nr_system = DEC_NR_SYS;
    return os;
}

//selects the hexadecimal number system
O_Stream& O_Stream::hex(O_Stream& os)  {
    os.selected_nr_system = HEX_NR_SYS;
    return os;
}






O_Stream& convert_long_to_list(O_Stream& os, unsigned long abs_number, int selected_nr_system, bool is_negative){


    //val to compute modula with
    switch(selected_nr_system){
        case BIN_NR_SYS: os << "0b"; break;
        case OCT_NR_SYS: os << "0o"; break;
        case HEX_NR_SYS: os << "0x"; break;

    }
    // '-' is the 45 in the ascii table
    if(is_negative) os << '-';

    char array_of_digits[64];
    int ctr = 0;

    if(abs_number == 0){
        os.put('0');
    }
    while(abs_number != 0){
        auto digit = abs_number % selected_nr_system;

        array_of_digits[ctr] = digit > 9 ? digit + 87 : digit + 48;
        abs_number /= selected_nr_system;
        ctr++;
    }
    while (ctr > 0){
        ctr--;
        os.put(array_of_digits[ctr]);
    }
    return os;

}



