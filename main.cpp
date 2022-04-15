#include <iostream>
#include <fstream>
#include <sstream>  

#include "MODULES/BINARY_TO_UNARY.h"

using namespace std;

int main(int argc, char* argv[]) {
    // opening the input from the file
    ifstream inputFile;
    stringstream s_option;
    inputFile.open(argv[1]);

    // variable declaraion
    string temporary;
    string tape_i = "";
    string tape_o = "";
    int option;

    inputFile >> temporary;
    s_option << temporary;
    s_option >> option;
    
    while (inputFile >> temporary) {
        tape_i += temporary;
    }

    switch (option) {
    case 0: {
        // unary to binary

    }
    case 1: {
        // binary to unary
        binary_to_unary(tape_i, tape_o);
    }
    case 2: {
        // binary to decimal
    }
    case 3: {
        // decimal to binary
    }
    }
}