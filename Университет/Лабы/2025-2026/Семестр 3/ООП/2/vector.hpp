// author: Danila "akshin_" Axyonov

#ifndef VECTOR__HPP
#define VECTOR__HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

namespace Lab2
{


template <typename T>
class vector {
private:
    T*          data__;
    std::size_t size__;

public:
    explicit vector(std::size_t init_size = 0, const T& value = T{});
    vector(const vector<T>& obj);
    vector(vector<T>&& obj) noexcept;
    ~vector() noexcept;
    vector<T>& operator=(const vector<T>& obj);
    vector<T>& operator=(vector<T>&& obj) noexcept;
    std::size_t size() const noexcept;
    void resize(std::size_t new_size, const T& value = T{}, bool fill = false);
    vector<T> operator+(const vector<T>& obj) const;
    vector<T>& operator+=(const vector<T>& obj);
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    template <typename T1>
    friend std::ostream& operator<<(std::ostream& out, const vector<T1>& obj);
    template <typename T1>
    friend std::istream& operator>>(std::istream& in, vector<T1>& obj);
};





template <typename T>
vector<T>::vector(std::size_t init_size, const T& value) {
    size__ = init_size;
    data__ = new T[size__];
    for (std::size_t i = 0; i < size__; ++i)
        data__[i] = value;
}

template <typename T>
vector<T>::vector(const vector<T>& obj) {
    size__ = obj.size__;
    data__ = new T[size__];
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
    if (this != &obj)
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
void vector<T>::resize(std::size_t new_size, const T& value, bool fill) {
    if (size__ == new_size) {
        if (fill)
            for (std::size_t i = 0; i < size__; ++i)
                data__[i] = value;
        return;
    }
    
    T* new_data = new T[new_size];
    if (fill)
        for (std::size_t i = 0; i < new_size; ++i)
            new_data[i] = value;
    else {
        std::size_t min_size = std::min(size__, new_size);
        for (std::size_t i = 0; i < min_size; ++i)
            new_data[i] = std::move(data__[i]);
        for (std::size_t i = min_size; i < new_size; ++i)
            new_data[i] = value;
    }
    delete[] data__;
    size__ = new_size;
    data__ = new_data;
}

template <typename T>
vector<T> vector<T>::operator+(const vector<T>& obj) const {
    if (size__ != obj.size__)
        throw std::domain_error("SIZES OF THE ADDED VECTOR ARE UNEQUAL.");
    
    vector<T> result = *this;
    for (std::size_t i = 0; i < size__; ++i)
        result.data__[i] += obj.data__[i];
    return result;
}

template <typename T>
vector<T>& vector<T>::operator+=(const vector<T>& obj) {
    if (size__ != obj.size__)
        throw std::domain_error("SIZES OF THE ADDED VECTOR ARE UNEQUAL.");
    
    for (std::size_t i = 0; i < size__; ++i)
        data__[i] += obj.data__[i];
    return *this;
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

template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& obj) {
    if (obj.size__ > 0)
        out << obj.data__[0];
    for (std::size_t i = 1; i < obj.size__; ++i)
        out << ' ' << obj.data__[i];
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, vector<T>& obj) {
    for (std::size_t i = 0; i < obj.size__; ++i)
        in >> obj.data__[i];
    return in;
}


}

#endif
