// author: Danila "akshin_" Axyonov

#ifndef VECTOR__HPP
#define VECTOR__HPP

#include <iostream>

namespace Lab2
{


template <typename T>
class vector {
private:
    T*          data__;
    std::size_t size__;

public:
    explicit vector(std::size_t init_size = 0); // TODO
    vector(const vector<T>& obj); // TODO
    vector(vector<T>&& obj) noexcept; // TODO
    ~vector() noexcept; // TODO
    vector<T>& operator=(const vector<T>& obj); // TODO
    vector<T>& operator=(vector<T>&& obj) noexcept; // TODO
    std::size_t size() const noexcept; // TODO
    std::size_t capacity() const noexcept; // TODO
    void resize(std::size_t new_size); // TODO
    vector<T> operator+(const vector<T>& obj) const; // TODO; почленно
    vector<T>& operator+=(const vector<T>& obj); // TODO; почленно
    T& operator[](std::size_t index); // TODO
    const T& operator[](std::size_t index) const; // TODO

    template <typename T1>
    friend std::ostream& operator<<(std::ostream& out, const vector<T1>& obj); // TODO
    template <typename T1>
    friend std::istream& operator>>(std::istream& in, vector<T1>& obj); // TODO
};


}

#endif

