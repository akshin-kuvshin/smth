#include <iostream>
using namespace std;

int gcd_R(int, int);

int main() {
    int a,
        b;
    cin >> a >> b;
    cout << gcd_R(a, b) << '\n';
    return 0;
}

int gcd_R(int b, int a) {
    int c = b % a;
    if (!c) return a;
    return gcd_R(a, c);
}
