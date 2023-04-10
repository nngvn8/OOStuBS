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

std::list<char> convert_long_to_list(long i){
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
    return char_list;

}

/* Add your code here */ 
