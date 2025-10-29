// author: Danila "akshin_" Axyonov

#ifndef MATRIX__HPP
#define MATRIX__HPP

#include "vector.hpp"
#include <iostream>

namespace Lab2
{


template <typename T>
class matrix {
private:
    vector<T>* data__;
    std::size_t rows__,
                cols__;

public:
    explicit matrix(std::size_t init_rows = 0, std::size_t init_cols = 0); // TODO
    matrix(const matrix<T>& obj); // TODO
    matrix(matrix<T>&& obj) noexcept; // TODO
    ~matrix() noexcept; // TODO
    matrix<T>& operator=(const matrix<T>& obj); // TODO
    matrix<T>& operator=(matrix<T>&& obj) noexcept; // TODO
    std::size_t rows() const noexcept; // TODO
    std::size_t cols() const noexcept; // TODO
    void resize(std::size_t new_rows, std::size_t new_cols, const T& value = T{}, bool fill = false); // TODO
    matrix<T> operator+(const matrix<T>& obj) const; // TODO
    matrix<T>& operator+=(const matrix<T>& obj); // TODO
    vector<T>& operator[](std::size_t index); // TODO
    const vector<T>& operator[](std::size_t index) const; // TODO
    
    template <typename T>
    friend std::ostream& operator<<(std::ostream& out, const matrix<T>& obj); // TODO
    template <typename T>
    friend std::istream& operator>>(std::istream& in, matrix<T>& obj); // TODO
};


}

#endif

