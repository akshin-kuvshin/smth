// author: Danila "akshin_" Axyonov

#include <iostream>
#include "CStr.hpp"
#include "CStrArray.hpp"
using std::cin,
      std::cout,
      std::endl;
using namespace Lab1;

int main() {
    const int N = 10;
    CStrArray a(N);
    
    a += new CStr("kings of tsu");
    a += new CStr(20);
    a += new CStr("Axyonov Danila");
    
    CStr* input = new CStr;
    cout << "Write some symbols (no more than 999) and then press enter:\n> ";
    cin >> *input;
    *input += " ending";
    a += input;
    
    
    cout << endl
         << a
         << (a.is_sorted_by_length() ? "[Sorted by length]" : "[Not sorted by length]") << endl
         << endl;
    
    
    a.sort_by_content();
    cout << a
         << (a.is_sorted_by_content() ? "[Sorted by content]" : "[Not sorted by content]") << endl
         << endl;
    
    
    a.sort_by_length(true);
    cout << a
         << (a.is_sorted_by_length(true) ? "[Sorted by length in descending order]" : "[Not sorted by length in descending order]") << endl
         << endl;
    
    
    cout << "Filled: " << a.get_size() << '/' << a.get_capacity() << '.' << endl;
    
    
    return 0;
}

