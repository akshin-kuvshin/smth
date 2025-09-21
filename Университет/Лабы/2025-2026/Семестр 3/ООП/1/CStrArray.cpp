// author: Danila "akshin_" Axyonov

#include "CStr.hpp"
#include "CStrArray.hpp"
#include <iostream>
#include <cassert>

namespace Lab1
{

using std::ostream;


CStrArray::CStrArray(int length) {
    assert(length >= 0 and "ERROR IN [inline CStrArray::CStrArray(int length)]: length have to be a non-negative number.");
    
    this->capacity = length;
    this->size = 0;
    
    this->array = new CStr*[this->capacity];
    assert(this->array and "ERROR: couldn't allocate memory.");
    for (int i = 0; i < this->capacity; ++i)
        this->array[i] = nullptr;
}

CStrArray::~CStrArray() {
    for (int i = 0; i < this->capacity; ++i)
        delete this->array[i];
    delete[] this->array;
    this->array = nullptr;
}

bool CStrArray::is_sorted(bool reverse) const {
    if (not reverse) {
        for (int i = 0; i + 1 < this->size; ++i)
            if (*(this->array[i]) > *(this->array[i + 1]))
                return false;
    } else {
        for (int i = 0; i + 1 < this->size; ++i)
            if (*(this->array[i]) < *(this->array[i + 1]))
                return false;
    }
    return true;
}

ostream& operator<<(ostream& stream, const CStrArray& objects) {
    for (int i = 0; i < objects.size; ++i)
        stream << objects[i] << '\n';
    return stream;
}


}

