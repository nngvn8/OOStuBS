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

void cga_stream_edge_case_test(){
    CGA_Stream cga_stream = CGA_Stream();
    int six = 6;
    cga_stream << "The char 'c' is actually " << (char)'c' << CGA_Stream::endl;
    cga_stream << "The unsigned char 'c' is actually " << (unsigned char)'c' << CGA_Stream::endl;
    cga_stream << "The number 6 is actually " << (unsigned short)6 << CGA_Stream::endl;
    cga_stream << "The number -6 is actually " << (short)(-6) << CGA_Stream::endl;
    cga_stream << "The number 2147483649 (2^31 + 1) is actually " << (unsigned int)2147483649 << CGA_Stream::endl;
    cga_stream << "The number 2147483647 (2^31 - 1) is actually " << 2147483647 << CGA_Stream::endl;
    cga_stream << "The number 9223372036854775809 (2^63 + 1) is actually " << (unsigned long)9223372036854775809 << CGA_Stream::endl;
    cga_stream << "The number 9223372036854775807 (2^63 - 1) is actually " << (long)9223372036854775807 << CGA_Stream::endl;
    cga_stream << "The address of the number 6 is " << &six << CGA_Stream::endl;
}

void cga_stream_manipulator_test(){
    CGA_Stream cga_stream = CGA_Stream();
    cga_stream << "There should be two line breaks between here " << CGA_Stream::endl;
    cga_stream << CGA_Stream::endl << "and here." << CGA_Stream::endl;
    cga_stream << "The number 6 in bin is " << CGA_Stream::bin << 6 << CGA_Stream::endl;
    cga_stream << "The number -6 in bin is " << CGA_Stream::bin << -6 << CGA_Stream::endl;
    cga_stream << "The number 6 in oct is " << CGA_Stream::oct << 6 << CGA_Stream::endl;
    cga_stream << "The number -6 in oct is " << CGA_Stream::oct << -6 << CGA_Stream::endl;
    cga_stream << "The number 6 in dec is " << CGA_Stream::dec << 6 << CGA_Stream::endl;
    cga_stream << "The number -6 in dec is " << CGA_Stream::dec << -6 << CGA_Stream::endl;
    cga_stream << "The number 6 in hex is " << CGA_Stream::hex << 6 << CGA_Stream::endl;
    cga_stream << "The number -6 in hex is " << CGA_Stream::hex << -6 << CGA_Stream::endl;
}

void cga_stream_color_setting_test(){
    CGA_Stream cga_stream = CGA_Stream();
    cga_stream << "Initial color is white on black." << CGA_Stream::endl;
    cga_stream.set_current_text_colour(CGA_COLORS::GREEN, CGA_COLORS::BLACK, false);
    cga_stream << "Now it should be green on black." << CGA_Stream::endl;
    cga_stream.set_current_text_colour(CGA_COLORS::BLACK, CGA_COLORS::WHITE,false);
    cga_stream << "Now it should be black on white and the next line should not be readable" << CGA_Stream::endl;
    cga_stream.set_current_text_colour(CGA_COLORS::WHITE, CGA_COLORS::WHITE, false);
    cga_stream << "White on white is silly." << CGA_Stream::endl;
    cga_stream.set_current_text_colour(CGA_COLORS::LIGHT_CYAN, CGA_COLORS::LIGHT_MAGENTA, false);
    cga_stream << "This color combo (light cyan on light magenta) should be illegal." << CGA_Stream::endl;
}