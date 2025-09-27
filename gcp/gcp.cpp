// author: Danila "akshin_" Axyonov

/*
"gcp" is a symbiosis of "g++" and "CP". This little program is a combination of standard g++ compiler and my set of flags for it which I use to compile my programs for CP (competitive programming). Actually, current set of flags was borrowed from USACO website (its author is Benq probably).

Usage example:
> gcp main
(!) the real name of file which is compiling is main.cpp.
*/

#include <iostream>
#include <string>
using namespace std;

const string COMPILER = "g++",
             STANDARD = "c++20",
             OPTIMIZATION_LEVEL = "2",
             WFLAGS = "-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wfloat-equal";

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        cerr << "ERROR: only 1 argument required, it must be .cpp-file." << endl;
        return 1;
    }

    const string name = argv[1];
    
    const string COMMAND =
        COMPILER +
        " " + name + ".cpp" +
        " -std=" + STANDARD +
        " -O" + OPTIMIZATION_LEVEL +
        " " + WFLAGS +
        " -o " + name;
    
    system(COMMAND.c_str());
    
    return 0;
}

