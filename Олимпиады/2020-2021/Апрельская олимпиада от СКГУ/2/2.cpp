#include <iostream>
using namespace std;

// Variables
char phoneNumber[12];
int shiftSize;

// Functions
void arrayInput();
void arrayOutput();
void cycleShiftToLeft();

int main() {
    // Input
    arrayInput();

    // Algorithm
    for (int i = 0; i < 12; i++)
        if (phoneNumber[i] == '+') {
            shiftSize = i;
            break;
        }
    cycleShiftToLeft();

    // Output
    arrayOutput();

    return 0;
}

void arrayInput() {
    for (int i = 0; i < 12; i++)
        cin >> phoneNumber[i];
}

void arrayOutput() {
    for (int i = 0; i < 12; i++)
        cout << phoneNumber[i] << (i != 11 ? " " : "");
    cout << '\n';
}

void cycleShiftToLeft() {
    int tmp[shiftSize];
    for (int i = 0; i < shiftSize; i++)
        tmp[i] = phoneNumber[i];

    for (int i = shiftSize; i < 12; i += 1)
        phoneNumber[i - shiftSize] = phoneNumber[i];

    for (int i = 12 - shiftSize, j = 0; i < 12; i += 1, j += 1)
        phoneNumber[i] = tmp[j];
}
