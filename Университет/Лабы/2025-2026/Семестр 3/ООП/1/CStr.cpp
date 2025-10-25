// author: Danila "akshin_" Axyonov

#include "CStr.hpp"
#include <iostream>
#include <cassert>

namespace Lab1
{

using namespace std;


char* CStr::rnd_gen(int length) const {
    const int LETTERS_NUMBER = 26;
    
    char* new_line = new char[length + 1];
    assert(new_line and "ERROR: couldn't allocate memory.");
    for (int i = 0; i < length; ++i)
        new_line[i] = 'a' + rand() % LETTERS_NUMBER;
    new_line[length] = '\0';
    
    return new_line;
}

ostream& operator<<(ostream& stream, const CStr& object) {
    stream << object.line;
    return stream;
}

istream& operator>>(istream& stream, CStr& object) {
    const int MAX_BUFFER_SIZE = 1'000;
    char buffer[MAX_BUFFER_SIZE];
    stream.getline(buffer, MAX_BUFFER_SIZE);
    
    delete[] object.line;
    object.line = object.copy(buffer);
    
    return stream;
}


}

