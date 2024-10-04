#include <iostream>
#include <string>
using namespace std;

// Variables
int cube[] = {1, 2, 6, 5, 3, 4},
    sz;
string S;

// Functions
void input();
void solution();
void output();
void R();
void L();
void U();
void D();
void C();
void A();

int main() {
    input();
    solution();
    output();

    return 0;
}

void input() {
    cin >> S;
}

void solution() {
    sz = S.size();
    for (size_t i = 0; i < sz; i++) {
        if ('R' == S.at(i))
            R();
        else if ('L' == S.at(i))
            L();
        else if ('U' == S.at(i))
            U();
        else if ('D' == S.at(i))
            D();
        else if ('C' == S.at(i))
            C();
        else if ('A' == S.at(i))
            A();
    }
}

void output() {
    cout << cube[4] << '\n';
}

void R() {
    swap(cube[2], cube[3]);
    swap(cube[1], cube[2]);
    swap(cube[0], cube[1]);
}

void L() {
    swap(cube[0], cube[1]);
    swap(cube[1], cube[2]);
    swap(cube[2], cube[3]);
}

void U() {
    swap(cube[3], cube[5]);
    swap(cube[3], cube[4]);
    swap(cube[1], cube[4]);
}

void D() {
    swap(cube[1], cube[4]);
    swap(cube[3], cube[4]);
    swap(cube[3], cube[5]);
}

void C() {
    swap(cube[0], cube[5]);
    swap(cube[2], cube[5]);
    swap(cube[2], cube[4]);
}

void A() {
    swap(cube[2], cube[4]);
    swap(cube[2], cube[5]);
    swap(cube[0], cube[5]);
}
