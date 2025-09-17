#include "CStr.hpp"
#include <cassert>
#include <cstdlib>
#include <cstring>

namespace Lab1
{


char* CStr::rnd_gen(int length) {
    const int LETTERS_NUMBER = 26;
    
    char* new_line = new char[length + 1];
    assert(new_line and "ERROR: couldn't allocate memory.");
    for (int i = 0; i < length; ++i)
        new_line[i] = 'a' + rand() % LETTERS_NUMBER;
    new_line[length] = '\0';
    
    return new_line;
}

char* CStr::copy(const char* source) {
    int length = strlen(source);
    char* new_line = new char[length + 1];
    assert(new_line and "ERROR: couldn't allocate memory.");
    memcpy(new_line, source, length + 1);
    return new_line;
}

char* CStr::copy(const CStr& object) {
    return this->copy(object.line);
}

inline CStr::CStr() {
    const int MIN_LENGTH = 1,
              MAX_LENGTH = 20;
    
    int length = MIN_LENGTH + rand() % (MAX_LENGTH - MIN_LENGTH + 1);
    this->line = this->rnd_gen(length);
}

inline CStr::CStr(const char* source) {
    assert(source and "ERROR IN [CStr::CStr(const char* source)]: source can't be a NULL-pointer.");
    this->line = this->copy(source);
}

inline CStr::CStr(int length) {
    assert(length <= 20 and "ERROR IN [CStr::CStr(int length)]: length have to be no more than 20.");
    this->line = this->rnd_gen(length);
}

inline CStr::CStr(const CStr& object) {
    this->line = this->copy(object);
}

inline CStr::~CStr() {
    delete[] this->line;
    this->line = nullptr;
}

inline CStr& CStr::operator=(const char* source) {
    assert(source and "ERROR IN [CStr& CStr::operator=(const char* source)]: source can't be a NULL-pointer.");
    
    delete[] this->line;
    this->line = this->copy(source);
    return *this;
}

inline CStr& CStr::operator=(const CStr& object) {
    if (this == &object)
        return *this;
    
    delete[] this->line;
    this->line = this->copy(object);
    return *this;
}


}

