//
// Created by benedict on 11.05.23.
//

#ifndef OOSTUBBS_MBJ_KB_PROLOGUE_CHAR_BUF_H
#define OOSTUBBS_MBJ_KB_PROLOGUE_CHAR_BUF_H

#include "machine/key.h"

#define BUFFER_SIZE 8

class Kb_prologue_char_buf{
private:
    int size = BUFFER_SIZE;
    Key buffer[BUFFER_SIZE];
    int next_in;
    int next_out;

public:
    Kb_prologue_char_buf() {
        next_in = 0;
        next_out = 0;
    }

    void produce(Key key) {
        if((next_in+1) % size == next_out) return;
        buffer[next_in] = key;
        next_in = (next_in+1)%size;
    }

    Key consume() {
        Key invalid;
        if(next_out == next_in) return invalid;
        Key result = buffer[next_out];
        next_out = (next_out +1) % size;
        return result;
    }

    int buffer_size(){
        return this->size;
    }
};
#endif //OOSTUBBS_MBJ_KB_PROLOGUE_CHAR_BUF_H
