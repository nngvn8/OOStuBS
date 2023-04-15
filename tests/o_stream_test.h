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
}

void cga_stream_color_setting_test(){
    CGA_Stream cga_stream = CGA_Stream();
    cga_stream << "Initial color is white on black." << CGA_Stream::endl;
    cga_stream.set_current_text_colour(CGA_COLORS::GREEN, CGA_COLORS::BLACK);
    cga_stream << "Now it should be green on black." << CGA_Stream::endl;
    cga_stream.set_current_text_colour(CGA_COLORS::BLACK, CGA_COLORS::WHITE);
    cga_stream << "Now it should be black on white and the next line should not be readable" << CGA_Stream::endl;
    cga_stream.set_current_text_colour(CGA_COLORS::WHITE, CGA_COLORS::WHITE);
    cga_stream << "White on white is silly." << CGA_Stream::endl;
    cga_stream.set_current_text_colour(CGA_COLORS::LIGHT_CYAN, CGA_COLORS::LIGHT_MAGENTA);
    cga_stream << "This color combo (light cyan on light magenta) should be illegal." << CGA_Stream::endl;
}