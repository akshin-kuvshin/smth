// author: Danila "akshin_" Axyonov

#include "CStr.hpp"
#include "CStrArray.hpp"
#include <iostream>
#include <cassert>

namespace Lab1
{

using namespace std;


bool cmp_by_content(const CStr* s1, const CStr* s2) {
    return *s1 < *s2;
}

bool cmp_by_content_rev(const CStr* s1, const CStr* s2) {
    return *s1 > *s2;
}

bool cmp_by_length(const CStr* s1, const CStr* s2) {
    return s1->get_length() < s2->get_length();
}

bool cmp_by_length_rev(const CStr* s1, const CStr* s2) {
    return s1->get_length() > s2->get_length();
}


void CStrArray::selection_sort(bool (*cmp)(const CStr*, const CStr*)) {
    for (int i = 0; i + 1 < this->size; ++i) {
        CStr* min_s = this->array[i];
        int min_ind = i;
        for (int j = i + 1; j < this->size; ++j)
            if (cmp(this->array[j], min_s)) {
                min_s = this->array[j];
                min_ind = j;
            }
        swap(this->array[i], this->array[min_ind]);
    }
}

bool CStrArray::is_sorted(bool (*cmp)(const CStr*, const CStr*)) const {
    for (int i = 0; i + 1 < this->size; ++i)
        if (not cmp(this->array[i], this->array[i + 1]) and *(this->array[i]) != *(this->array[i + 1]))
            return false;
    return true;
}

CStrArray::CStrArray(int length) {
    assert(length >= 0 and "ERROR IN [CStrArray::CStrArray(int length)]: length have to be a non-negative number.");
    
    this->capacity = length;
    this->size = 0;
    
    this->array = new CStr*[this->capacity];
    assert(this->array and "ERROR: couldn't allocate memory.");
    for (int i = 0; i < this->capacity; ++i)
        this->array[i] = nullptr;
}

CStrArray::CStrArray(const CStrArray& objects) {
    this->capacity = objects.capacity;
    this->size = objects.size;
    
    this->array = new CStr*[this->capacity];
    assert(this->array and "ERROR: couldn't allocate memory.");
    for (int i = 0; i < this->size; ++i) {
        this->array[i] = new CStr(*objects[i]);
        assert(this->array[i] and "ERROR: couldn't allocate memory.");
    }
    for (int i = this->size; i < this->capacity; ++i)
        this->array[i] = nullptr;
}

CStrArray::~CStrArray() {
    for (int i = 0; i < this->capacity; ++i)
        delete this->array[i];
    delete[] this->array;
}

CStrArray& CStrArray::operator=(const CStrArray& objects) {
    if (this == &objects)
        return *this;
    
    for (int i = 0; i < this->capacity; ++i)
        delete this->array[i];
    delete[] this->array;
    
    this->capacity = objects.capacity;
    this->size = objects.size;
    
    this->array = new CStr*[this->capacity];
    assert(this->array and "ERROR: couldn't allocate memory.");
    for (int i = 0; i < this->size; ++i) {
        this->array[i] = new CStr(*objects[i]);
        assert(this->array[i] and "ERROR: couldn't allocate memory.");
    }
    for (int i = this->size; i < this->capacity; ++i)
        this->array[i] = nullptr;
    
    return *this;
}

ostream& operator<<(ostream& stream, const CStrArray& objects) {
    for (int i = 0; i < objects.size; ++i)
        stream << *objects[i] << '\n';
    return stream;
}


}

