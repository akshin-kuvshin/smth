// author: Danila "akshin_" Axyonov

#ifndef MATRIX__HPP
#define MATRIX__HPP

#include "vector.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>

namespace Lab2
{


template <typename T>
class matrix {
private:
    vector<T>* data__;
    std::size_t rows__,
                cols__;

public:
    explicit matrix(std::size_t init_rows = 0, std::size_t init_cols = 0, const T& value = T{});
    matrix(const matrix<T>& obj);
    matrix(matrix<T>&& obj) noexcept;
    ~matrix() noexcept;
    matrix<T>& operator=(const matrix<T>& obj);
    matrix<T>& operator=(matrix<T>&& obj) noexcept;
    std::size_t rows() const noexcept;
    std::size_t cols() const noexcept;
    void resize(std::size_t new_rows, std::size_t new_cols, const T& value = T{}, bool fill = false);
    matrix<T> operator+(const matrix<T>& obj) const;
    matrix<T>& operator+=(const matrix<T>& obj);
    vector<T>& operator[](std::size_t index);
    const vector<T>& operator[](std::size_t index) const;
    
    template <typename T1>
    friend std::ostream& operator<<(std::ostream& out, const matrix<T1>& obj);
    template <typename T1>
    friend std::istream& operator>>(std::istream& in, matrix<T1>& obj);
};





template <typename T>
matrix<T>::matrix(std::size_t init_rows, std::size_t init_cols, const T& value) {
    rows__ = init_rows;
    cols__ = init_cols;
    data__ = new vector<T>[rows__];
    for (std::size_t i = 0; i < rows__; ++i)
        data__[i].resize(cols__, value);
}

template <typename T>
matrix<T>::matrix(const matrix<T>& obj) {
    rows__ = obj.rows__;
    cols__ = obj.cols__;
    data__ = new vector<T>[rows__];
    for (std::size_t i = 0; i < rows__; ++i)
        data__[i] = obj.data__[i];
}

template <typename T>
matrix<T>::matrix(matrix<T>&& obj) noexcept {
    rows__ = obj.rows__;
    cols__ = obj.cols__;
    data__ = obj.data__;

    obj.rows__ = 0;
    obj.cols__ = 0;
    obj.data__ = nullptr;
}

template <typename T>
matrix<T>::~matrix() noexcept {
    delete[] data__;
}

template <typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& obj) {
    if (this != &obj)
        *this = matrix<T>(obj);
    return *this;
}

template <typename T>
matrix<T>& matrix<T>::operator=(matrix<T>&& obj) noexcept {
    delete[] data__;
    rows__ = obj.rows__;
    cols__ = obj.cols__;
    data__ = obj.data__;

    obj.rows__ = 0;
    obj.cols__ = 0;
    obj.data__ = nullptr;

    return *this;
}

template <typename T>
std::size_t matrix<T>::rows() const noexcept {
    return rows__;
}

template <typename T>
std::size_t matrix<T>::cols() const noexcept {
    return cols__;
}

template <typename T>
void matrix<T>::resize(std::size_t new_rows, std::size_t new_cols, const T& value, bool fill) {
    if (rows__ == new_rows) {
        for (std::size_t i = 0; i < rows__; ++i)
            data__[i].resize(new_cols, value, fill);
        cols__ = new_cols;
        return;
    }

    vector<T>* new_data = new vector<T>[new_rows];
    std::size_t min_rows = std::min(rows__, new_rows);
    for (std::size_t i = 0; i < min_rows; ++i)
        new_data[i] = std::move(data__[i]);
    for (std::size_t i = 0; i < new_rows; ++i)
        new_data[i].resize(new_cols, value, fill);
    
    delete[] data__;
    rows__ = new_rows;
    cols__ = new_cols;
    data__ = new_data;
}

template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& obj) const {
    if (rows__ != obj.rows__ or cols__ != obj.cols__)
        throw std::domain_error("SIZES OF THE ADDED MATRIXES ARE UNEQUAL.");
    
    matrix<T> result = *this;
    for (std::size_t i = 0; i < rows__; ++i)
        result.data__[i] += obj.data__[i];
    return result;
}

template <typename T>
matrix<T>& matrix<T>::operator+=(const matrix<T>& obj) {
    if (rows__ != obj.rows__ or cols__ != obj.cols__)
        throw std::domain_error("SIZES OF THE ADDED MATRIXES ARE UNEQUAL.");
    
    for (std::size_t i = 0; i < rows__; ++i)
        data__[i] += obj.data__[i];
    return *this;
}

template <typename T>
vector<T>& matrix<T>::operator[](std::size_t index) {
    if (index >= rows__)
        throw std::out_of_range("INVALID INDEX.");
    return data__[index];
}

template <typename T>
const vector<T>& matrix<T>::operator[](std::size_t index) const {
    if (index >= rows__)
        throw std::out_of_range("INVALID INDEX.");
    return data__[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const matrix<T>& obj) {
    if (obj.rows__ > 0)
        out << obj.data__[0];
    for (std::size_t i = 1; i < obj.rows__; ++i)
        out << std::endl << obj.data__[i];
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, matrix<T>& obj) {
    for (std::size_t i = 0; i < obj.rows__; ++i)
        in >> obj.data__[i];
    return in;
}


}

#endif
