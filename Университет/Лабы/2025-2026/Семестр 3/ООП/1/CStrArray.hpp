// author: Danila "akshin_" Axyonov

#ifndef CSTRARRAY_HPP
#define CSTRARRAY_HPP

#include "CStr.hpp"
#include <iostream>
#include <cassert>

namespace Lab1
{

using namespace std;


bool cmp_by_content(const CStr* s1, const CStr* s2);
bool cmp_by_content_rev(const CStr* s1, const CStr* s2);
bool cmp_by_length(const CStr* s1, const CStr* s2);
bool cmp_by_length_rev(const CStr* s1, const CStr* s2);


class CStrArray {
private:
    CStr** array;
    int capacity;
    int size;
    
    void selection_sort(bool (*cmp)(const CStr*, const CStr*));
    bool is_sorted(bool (*cmp)(const CStr*, const CStr*)) const;

public:
    CStrArray(int length);
    CStrArray(const CStrArray& objects);
    ~CStrArray();
    CStrArray& operator=(const CStrArray& objects);
    friend ostream& operator<<(ostream& stream, const CStrArray& objects);
    
    CStrArray& operator+=(CStr* object) {
        assert(object and "ERROR IN [CStrArray& CStrArray::operator+=(CStr* object)]: object can't be a null-pointer.");
        assert(this->size < this->capacity and "ERROR IN [CStrArray& CStrArray::operator+=(CStr* object)]: there is no enough space to add the object to the array.");
        
        this->array[this->size++] = object;
        return *this;
    }
    
    CStr* operator[](int index) {
        assert(0 <= index and
               index < this->size and
               "ERROR IN [CStr* CStrArray::operator[](int index)]: invalid index.");
        return this->array[index];
    }
    
    const CStr* operator[](int index) const {
        assert(0 <= index and
               index < this->size and
               "ERROR IN [CStr* CStrArray::operator[](int index)]: invalid index.");
        return this->array[index];
    }
    
    int get_capacity() const {
        return this->capacity;
    }
    
    int get_size() const {
        return this->size;
    }
    
    void sort_by_content(bool reverse = false) {
        this->selection_sort(not reverse ? cmp_by_content : cmp_by_content_rev);
    }
    
    void sort_by_length(bool reverse = false) {
        this->selection_sort(not reverse ? cmp_by_length : cmp_by_length_rev);
    }
    
    bool is_sorted_by_content(bool reverse = false) const {
        return this->is_sorted(not reverse ? cmp_by_content : cmp_by_content_rev);
    }
    
    bool is_sorted_by_length(bool reverse = false) const {
        return this->is_sorted(not reverse ? cmp_by_length : cmp_by_length_rev);
    }
};


}

#endif

