#include "device/cgastr.h"

void o_stream_hello_w(){

    CGA_Stream cga_stream = CGA_Stream();
    cga_stream << "Hello? World!" << O_Stream::endl;
    cga_stream << "ccc" << O_Stream::endl;
    cga_stream << "93248093284032" << O_Stream::endl;


    int a = 69;
    int b = 0;
    unsigned long c = 2131212323423322342;
    short d = -1;
    cga_stream << O_Stream::dec;

    cga_stream << a << O_Stream::bin << O_Stream::endl;
    cga_stream << a << O_Stream::oct<< O_Stream::endl;

    cga_stream << a << O_Stream::dec<< O_Stream::endl;
    cga_stream << a << O_Stream::hex<< O_Stream::endl;

    cga_stream << &a << O_Stream::endl;

    cga_stream << b << O_Stream::endl;
    cga_stream << &b << O_Stream::endl;

    cga_stream << c << O_Stream::endl;
    cga_stream << &c << O_Stream::endl;

    cga_stream << d << O_Stream::endl;

    cga_stream << "osdifjwoeirjwoeirjweiorjwoeirjwoaljlwejqwiojeqwoiejqowiejqoiwejqoiwejqoweijqwoiejeirjoi";

    cga_stream << b << O_Stream::endl;

    cga_stream << "qwert,zuio,asdf,ghjk,lyxc,vbna,sd";

    cga_stream << '\n'<< O_Stream::endl;

    cga_stream << a << O_Stream::bin<< O_Stream::endl;

    cga_stream << -8 << O_Stream::endl;
    cga_stream << -0 << O_Stream::endl;
    cga_stream << (long)-1 << O_Stream::endl;


    //01000
    //10111
    //11000





}



