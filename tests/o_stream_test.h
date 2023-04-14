#include "device/cgastr.h"

void o_stream_hello_w(){

    CGA_Stream cga_stream = CGA_Stream();
    cga_stream << "Hello? World!" << O_Stream::endl;
    cga_stream << 69 << O_Stream::bin;
    cga_stream << "osdifjwoeirjwoeirjweiorjwoeirjwoaljlwejqwiojeqwoiejqowiejqoiwejqoiwejqoweijqwoiejeirjoi";
    cga_stream.flush();



}



