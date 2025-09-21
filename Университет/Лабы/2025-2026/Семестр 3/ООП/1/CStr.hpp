// author: Danila "akshin_" Axyonov

#ifndef CSTR_HPP
#define CSTR_HPP

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>

namespace Lab1
{

using std::ostream,
      std::istream;


class CStr {
private:
    char* line;
    char* rnd_gen(int length) const;
    
    char* copy(const char* source) const {
        int length = strlen(source);
        char* new_line = new char[length + 1];
        assert(new_line and "ERROR: couldn't allocate memory.");
        memcpy(new_line, source, length);
        new_line[length] = '\0';
        return new_line;
    }
    
    char* copy(const CStr& object) const {
        return this->copy(object.line);
    }
    
    char* concat(const CStr& object) const {
        int length1 = this->get_length(),
            length2 = object.get_length();
        int result_length = length1 + length2;
        
        char* result_line = new char[result_length + 1];
        assert(result_line and "ERROR: couldn't allocate memory.");
        memcpy(result_line, this->line, length1);
        memcpy(result_line + length1, object.line, length2);
        result_line[result_length] = '\0';
        
        return result_line;
    }

public:
    CStr() {
        const int MIN_LENGTH = 1,
                  MAX_LENGTH = 20;
        
        int length = MIN_LENGTH + rand() % (MAX_LENGTH - MIN_LENGTH + 1);
        this->line = this->rnd_gen(length);
    }
    
    CStr(const char* source) {
        assert(source and "ERROR IN [inline CStr::CStr(const char* source)]: source can't be a NULL-pointer.");
        this->line = this->copy(source);
    }
    
    CStr(int length) {
        assert(length <= 20 and "ERROR IN [inline CStr::CStr(int length)]: length have to be no more than 20.");
        this->line = this->rnd_gen(length);
    }
    
    CStr(const CStr& object) {
        this->line = this->copy(object);
    }
    
    ~CStr() {
        delete[] this->line;
        this->line = nullptr;
    }
    
    CStr& operator=(const char* source) {
        assert(source and "ERROR IN [inline CStr& CStr::operator=(const char* source)]: source can't be a NULL-pointer.");
        
        delete[] this->line;
        this->line = this->copy(source);
        return *this;
    }
    
    CStr& operator=(const CStr& object) {
        if (this == &object)
            return *this;
        
        delete[] this->line;
        this->line = this->copy(object);
        return *this;
    }
    
    CStr operator+(const CStr& object) const {
        char* result_line = this->concat(object);    
        CStr result(result_line);
        delete[] result_line;
        return result;
    }
    
    CStr& operator+=(const CStr& object) {
        char* result_line = this->concat(object);
        delete[] this->line;
        this->line = result_line;
        return *this;
    }
    
    bool operator==(const CStr& object) const {
        return strcmp(this->line, object.line) == 0;
    }
    
    bool operator!=(const CStr& object) const {
        return strcmp(this->line, object.line) != 0;
    }
    
    bool operator<(const CStr& object) const {
        return strcmp(this->line, object.line) < 0;
    }
    
    bool operator<=(const CStr& object) const {
        return strcmp(this->line, object.line) <= 0;
    }
    
    bool operator>(const CStr& object) const {
        return strcmp(this->line, object.line) > 0;
    }
    
    bool operator>=(const CStr& object) const {
        return strcmp(this->line, object.line) >= 0;
    }
    
    char& operator[](int index) {
        assert(0 <= index and
               index < this->get_length() and
               "ERROR IN [inline char& CStr::operator[](int index)]: invalid index.");
        return this->line[index];
    }
    
    char operator[](int index) const {
        assert(0 <= index and
               index < this->get_length() and
               "ERROR IN [inline char CStr::operator[](int index) const]: invalid index.");
        return this->line[index];
    }
    
    int get_length() const {
        return strlen(this->line);
    }
    
    friend ostream& operator<<(ostream& stream, const CStr& object);
    friend istream& operator>>(istream& stream, CStr& object);
};


}


#endif

