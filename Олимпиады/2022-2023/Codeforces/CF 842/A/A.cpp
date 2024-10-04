#include <iostream>
#include <array>
using namespace std;

// Constants
const int T_max = 1e4;

// Variables
int tests_number;
array<int, T_max + 5> answers;

int K;

// Functions
int main() {
    cin >> tests_number;
    
    for (int t = 0; t < tests_number; ++t) {
        cin >> K;
        answers[t] = K - 1;
    }

    for (int t = 0; t < tests_number; ++t)
        cout << answers[t] << '\n';

    return 0;
}
