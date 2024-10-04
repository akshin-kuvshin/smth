#include <iostream>
#include <string>
using namespace std;

// Variables
int housesAmount;
string s1 = "  /\\   ";
string s2 = " /  \\  ";
string s3 = " ____  ";
string s4 = "|     |";
string s5 = "| [ ] |";
string s6 = " _____ ";

// Functions
void output(string);

int main() {
    // Input
    cin >> housesAmount;

    // Output's algorithm
    output(s1);
    output(s2);
    output(s3);
    output(s4);
    output(s5);
    output(s6);

    return 0;
}

void output(string S) {
    cout << S;
    for (int i = 1; i < housesAmount; i++) {
        cout << ' ' << S;
    }
    cout << '\n';
}
