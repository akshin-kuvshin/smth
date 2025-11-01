// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include "vector.hpp"
#include "matrix.hpp"

int main() {
    Lab2::matrix<int> a(5, 2, 123);
    std::cout << a << std::endl;



    a.resize(6, 10, 228);
    std::cout << std::endl
              << a << std::endl;



    Lab2::vector<int> b(10, -15);
    b += b;
    b = b + b + b;
    std::cout << std::endl
              << b << std::endl;



    Lab2::matrix<int> c = a;
    c[4] = b;
    std::cout << std::endl
              << c << std::endl;



    Lab2::matrix<std::string> d(2, 2);
    std::cout << std::endl
              << "Enter 4 strings:" << std::endl;
    std::cin >> d;
    d += d;
    std::cout << std::endl
              << "Doubled:" << std::endl;
    std::cout << d << std::endl;

    return 0;
}
