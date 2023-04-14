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
    return convert_long_to_list(*this, (unsigned long)number, this->selected_nr_system, false , 16);
}
O_Stream& O_Stream::operator<< (short number) {
    unsigned long abs_number;
    number < 0 ? abs_number = -1*number : abs_number = (number) ;
    return convert_long_to_list(*this, abs_number, this->selected_nr_system, number < 0, 16 );
}
O_Stream& O_Stream::operator<< (unsigned int number) {
    return convert_long_to_list(*this, (unsigned long)number, this->selected_nr_system, false, 32);
}
O_Stream& O_Stream::operator<< (int number) {
    unsigned long abs_number;
    number < 0 ? abs_number = -1*number : abs_number = (number) ;
    return convert_long_to_list(*this, abs_number, this->selected_nr_system, number < 0 , 32);
}
O_Stream& O_Stream::operator<< (unsigned long number){
    return convert_long_to_list(*this, (unsigned long)number, this->selected_nr_system, false , 64);
}

O_Stream& O_Stream::operator<< (long number){
    unsigned long abs_number;
    number < 0 ? abs_number = -1*number : abs_number = (number) ;
    return convert_long_to_list(*this, abs_number, this->selected_nr_system, number < 0, 64 );
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






O_Stream& convert_long_to_list(O_Stream& os, unsigned long abs_number, int selected_nr_system, bool is_negative,  int bit_length_nr){


    //val to compute modula with
    switch(selected_nr_system){
        case BIN_NR_SYS: os << "0b"; break;
        case OCT_NR_SYS: os << "0o"; break;
        case HEX_NR_SYS: os << "0x"; break;

    }
    // '-' is the 45 in the ascii table
    //a & (-b or -a)
    // a&-b or a&-a
    if(is_negative && !(selected_nr_system == 2)) os << '-';

    char array_of_digits[64];
    int ctr = 0;

    if(abs_number == 0){
        os.put('0');
        return os;
    }

    while(abs_number != 0){
        auto digit = abs_number % selected_nr_system;

        array_of_digits[ctr] = digit > 9 ? digit + 87 : digit + 48;
        abs_number /= selected_nr_system;
        ctr++;
    }
    if(selected_nr_system == 2 && is_negative){
        t2er_complement(os, array_of_digits, bit_length_nr, ctr);
        return os;
    }

    while (ctr > 0){
        ctr--;
        os.put(array_of_digits[ctr]);
    }
    return os;

}

/**
 *
 * @param os
 * @param array__of_digits
 * @param array_length
 * @param bit_length_nr
 * @return
 */

void t2er_complement(O_Stream& os ,char* array__of_digits, int bit_length_nr, int ctr){

    char not_complemented_array[bit_length_nr];
    char final_array[bit_length_nr];
    //starts at 56, 57, 58, ... for ctr = 8 and bit_length_nr = 64
    //array_vals from 55,56, ... are meant to be set
    int runner = bit_length_nr - ctr;
    //error case , ctr > bit_length_nr
    if (runner < 0){
        os << "Fehlerfall: Wert passt nicht ins Array rein" << O_Stream::endl;
        return;
    }

    //fill with '0' until [runner-1]
    for(int i= 0; i < runner; i++ ){
        not_complemented_array[i] = 48;
    }
    //fill with given number until the rest of the array
    while(ctr > 0){
        ctr--;
        not_complemented_array[runner] = array__of_digits[ctr];
        runner++;
    }

    //flipping bits
    for(int i = 0 ; i < bit_length_nr; i ++ ){
        not_complemented_array[i] == 48 ? final_array[i] = 49 : final_array[i] = 48;
    }

    // calculate + 1
    int array_iterator = bit_length_nr -1 ;
    if(final_array[array_iterator] == 48) final_array[bit_length_nr-1] = 49;
    else if(final_array[array_iterator] == 49){
        while(final_array[array_iterator] == 49){
            final_array[array_iterator] = 48;
            array_iterator --;
        }
        final_array[array_iterator] = 49;
    }
    else{
        os << "Error: t2er_complement: neither a '1' nor a '2' at the end of the complemented number" << O_Stream::endl;
    }
    //put into the stream
    for(int i = 0; i < bit_length_nr; i++ ){
        os.put(final_array[i]);
    }

}





