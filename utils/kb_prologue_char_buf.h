//
// Created by benedict on 11.05.23.
//

#ifndef OOSTUBBS_MBJ_KB_PROLOGUE_CHAR_BUF_H
#define OOSTUBBS_MBJ_KB_PROLOGUE_CHAR_BUF_H

class Kb_prologue_char_buf{
private:
    int size = 8;
    char buffer[8];
    int next_in ;
    int next_out ;
public:
    Kb_prologue_char_buf() {
        next_in = 0;
        next_out = 0;
    }

    void produce(char c) {

        if((next_in+1) % size == next_out) return;
        buffer[next_in] = c;
        next_in = (next_in+1)%size;

    }
    char consume() {
        if(next_out == next_in) return 0;
        char result = buffer[next_out];
        next_out = (next_out +1) % size;
        return result;
    }
    int buffer_size(){
        return this->size;
    }
};
#endif //OOSTUBBS_MBJ_KB_PROLOGUE_CHAR_BUF_H
