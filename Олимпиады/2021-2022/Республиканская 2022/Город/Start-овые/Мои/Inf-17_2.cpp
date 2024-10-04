#include <iostream>
using namespace std;

// Variables
int x,
    y,
    z,
    a,
    b,
    c;

int _gcd(int num1, int num2) {
    if (num2)
        return _gcd(num2, num1 % num2);
    return num1;
}

void input() {
    cin >> x >> y >> z;
    return;
}

void solution() {
    a = _gcd(x, z);
    b = x / a;
    c = y / b;
    return;
}

void output() {
    cout << a << ' ' << b << ' ' << c << '\n';
    return;
}

int main() {
    input();
    solution();
    output();
    return 0;
}