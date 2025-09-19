// author: Danila "akshin_" Axyonov

#ifndef CSTR_HPP
#define CSTR_HPP

#include <iostream>

namespace Lab1
{

using std::ostream,
      std::istream;


class CStr {
private:
    char* line;
    char* rnd_gen(int length) const;
    char* copy(const char* source) const;
    char* copy(const CStr& object) const;
    char* concat(const CStr& object) const;

public:
    CStr();
    CStr(const char* source);
    CStr(int length);
    CStr(const CStr& object);
    ~CStr();
    CStr& operator=(const char* source);
    CStr& operator=(const CStr& object);
    CStr operator+(const CStr& object) const;
    CStr& operator+=(const CStr& object);
    bool operator==(const CStr& object) const;
    bool operator!=(const CStr& object) const;
    bool operator<(const CStr& object) const;
    bool operator<=(const CStr& object) const;
    bool operator>(const CStr& object) const;
    bool operator>=(const CStr& object) const;
    char& operator[](int index);
    char operator[](int index) const;
    int get_length() const;
    friend ostream& operator<<(ostream& stream, const CStr& object);
    friend istream& operator>>(istream& stream, CStr& object);
};


}


#endif

