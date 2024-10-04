#include <iostream>
using namespace std;

// Variables
int a,
    b,
    c,
    d,
    x,
    y,
    _ans;

int _min(int num1, int num2) {
    return ( (num1 < num2) ? num1 : num2);
}

void input() {
    cin >> a >> b >> c >> d;
    return;
}

void solution() {
    x = _min(a, c);
    y = _min(b, d);
    
    _ans = x * y;
    
    return;
}

void output() {
    cout << _ans << '\n';
    return;
}

int main() {
    input();
    solution();
    output();
    return 0;
}