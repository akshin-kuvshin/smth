// author: Danila "akshin_" Axyonov

#ifndef CSTRARRAY_HPP
#define CSTRARRAY_HPP

#include "CStr.hpp"
#include <iostream>
#include <cassert>

namespace Lab1
{

using std::ostream;


class CStrArray {
private:
    CStr** array;
    int capacity;
    int size;

public:
    CStrArray(int length);
    ~CStrArray();
    bool is_sorted(bool reverse = false) const;
    friend ostream& operator<<(ostream& stream, const CStrArray& objects);
    
    CStrArray& operator+=(CStr* object) {
        assert(object and "ERROR IN [inline CStrArray& CStrArray::operator+=(CStr* object)]: object can't be a NULL-pointer.");
        assert(this->size < this->capacity and "ERROR IN [inline CStrArray& CStrArray::operator+=(CStr* object)]: there is no enough space to add the object to the array.");
        
        this->array[this->size++] = object;
        return *this;
    }
    
    CStr* operator[](int index) {
        assert(0 <= index and
               index < this->size and
               "ERROR IN [inline CStr* CStrArray::operator[](int index)]: invalid index.");
        return this->array[index];
    }
    
    const CStr* operator[](int index) const {
        assert(0 <= index and
               index < this->size and
               "ERROR IN [inline CStr* CStrArray::operator[](int index)]: invalid index.");
        return this->array[index];
    }
    
    void sort_by_content(bool reverse = false) {
        // TODO
    }
    
    void sort_by_length(bool reverse = false) {
        // TODO
    }
};


}

#endif

