#include <iostream>
#include <string>
using namespace std;

// Constants
const string PI = "314159265358979323846264338327";

// Variables
int t;
string S;
int answer;

// Functions
void input();
void solution();
void output();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while (t--) {
        input();
        solution();
        output();
    }
    return 0;
}

void input() {
    cin >> S;
    return;
}

void solution() {
    answer = 0;
    for (int i = 0; i < (int)S.size(); ++i) {
        if (S[i] != PI[i])
            break;
        ++answer;
    }
    return;
}

void output() {
    cout << answer << '\n';
    return;
}
