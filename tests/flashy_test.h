//
// Created by Julius Gilka-Bötzow on 13.04.23.
//

#include "device/cgastr.h"

/// The idea of this class is to encompass all other test and make them be callable by the user

void test_all_tests(){
    CGA_Stream cga = CGA_Stream();
    cga << "Hello World!" << CGA_Stream::endl;
}