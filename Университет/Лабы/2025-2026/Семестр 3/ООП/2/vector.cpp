// author: Danila "akshin_" Axyonov

#include "vector.hpp"

namespace Lab2
{


template <typename T>
vector<T>::vector(std::size_t init_size) {
    size__ = init_size;
    data__ = new T[size__]{};
}

template <typename T>
vector<T>::vector(const vector<T>& obj) : vector(obj.size__) {
    for (std::size_t i = 0; i < size__; ++i)
        data__[i] = obj.data__[i];
}

template <typename T>
vector<T>::vector(vector<T>&& obj) noexcept {
    size__ = obj.size__;
    data__ = obj.data__;
    
    obj.size__ = 0;
    obj.data__ = nullptr;
}

template <typename T>
vector<T>::~vector() noexcept {
    delete[] data__;
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& obj) {
    if (this == &obj)
        return *this;
    
    *this = vector<T>(obj);
    return *this;
}

template <typename T>
vector<T>& vector<T>::operator=(vector<T>&& obj) noexcept {
    delete[] data__;
    size__ = obj.size__;
    data__ = obj.data__;
    
    obj.size__ = 0;
    obj.data__ = nullptr;
    
    return *this;
}

template <typename T>
std::size_t vector<T>::size() const noexcept {
    return size__;
}

template <typename T>
T& vector<T>::operator[](std::size_t index) {
    if (index >= size__)
        throw std::out_of_range("INVALID INDEX.");
    return data__[index];
}

template <typename T>
const T& vector<T>::operator[](std::size_t index) const {
    if (index >= size__)
        throw std::out_of_range("INVALID INDEX.");
    return data__[index];
}


}

