#include <iostream>
#include <vector>
using namespace std;

#define plli            pair<int, int>

int main() {
    vector<char> A = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    for (char c1 : A) {
        for (char c2 : A)
            cout << c1 << c2 << ' ';
        cout << '\n';
    }
    return 0;
}
