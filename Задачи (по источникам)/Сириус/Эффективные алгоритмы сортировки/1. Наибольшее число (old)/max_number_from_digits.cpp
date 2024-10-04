#include <iostream>
#include <string>
using namespace std;

int digits[10];
string input;
bool is_there_any_digits;

int main() {
    getline(cin, input);

    int sz = input.size();
    for (int i = 0; i < sz; ++i)
        if (('0' <= input[i]) and (input[i] <= '9')) {
            ++digits[input[i] - '0'];
            is_there_any_digits = true;
        }
    
    for (int i = 9; i >= 0; --i)
        for (int j = 0; j < digits[i]; ++j)
            cout << i;
    
    if (!is_there_any_digits)
        cout << -1;
    
    cout << '\n';
    return 0;
}
