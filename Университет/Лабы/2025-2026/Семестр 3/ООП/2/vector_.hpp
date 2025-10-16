// author: Danila "akshin_" Axyonov

#ifndef VECTOR__HPP
#define VECTOR__HPP

#include <iostream>

namespace Lab2
{


template <typename T>
class vector_ {
private:
    T*          data_;
    std::size_t size_,
                capacity_;
    void realloc(std::size_t new_capacity);

public:
   explicit vector_(std::size_t init_size = 0); // TODO
   vector_(const vector_<T>& obj); // TODO
   vector_(vector_<T>&& obj) noexcept; // TODO
   ~vector_() noexcept; // TODO
   vector_<T>& operator=(const vector_<T>& obj); // TODO
   vector_<T>& operator=(vector_<T>&& obj) noexcept; // TODO
   std::size_t size() const noexcept; // TODO
   std::size_t capacity() const noexcept; // TODO
   void resize(std::size_t new_size); // TODO
   vector_<T> operator+(const vector_<T>& obj) const; // TODO; почленно
   vector_<T>& operator+=(const vector_<T>& obj); // TODO; почленно
   T& operator[](std::size_t index); // TODO
   const T& operator[](std::size_t index) const; // TODO
   
   template <typename T1>
   friend std::ostream& operator<<(std::ostream& out, const vector_<T1>& obj); // TODO
   template <typename T1>
   friend std::istream& operator>>(std::istream& in, vector_<T1>& obj); // TODO
};


}

#endif

