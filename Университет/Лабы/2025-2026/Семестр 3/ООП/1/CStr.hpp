#ifndef CSTR_HPP
#define CSTR_HPP


namespace Lab1
{


class CStr {
private:
    char* line;
    char* rnd_gen(int length);
    char* copy(const char* source);
    char* copy(const CStr& object);

public:
    CStr();
    CStr(const char* source);
    CStr(int length);
    CStr(const CStr& object);
    ~CStr();
    CStr& operator=(const char* source);
    CStr& operator=(const CStr& object);
};


}


#endif

