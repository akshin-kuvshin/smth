// author: Danila "akshin_" Axyonov

#include "SKbrd.hpp"
#include <iostream>

namespace Lab3
{


int SKbrd::get() {
    int num;
    if (not (std::cin >> num))
        return EOF;
    return num;
}


}
