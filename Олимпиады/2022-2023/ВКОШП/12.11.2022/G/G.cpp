#include <iostream>
#include <string>
using namespace std;

int N,
    M,
    palki,
    t;
string S;

void update();

int main() {
    cin >> N >> M;
    update();

    if (palki % 2 == 0) {
        cout << 2 << '\n';
        cout.flush();
    } else {
        cout << 1 << '\n';
        cout.flush();

        if (N == 1) {
            cout << "C 1\n";
            cout.flush();
            M = 1;
            update();
        } else if (M == 1) {
            cout << "R 1\n";
            cout.flush();
            N = 1;
            update();
        } else {
            if (N != 2) {
                cout << "R 2\n";
                cout.flush();
                N = 2;
                update();
            } else {
                cout << "C 2\n";
                cout.flush();
                M = 2;
                update();
            }
        }
    }

    while (true) {
        cin >> S;
        if (S != "R" and S != "C")
            break;
        cin >> t;

        if (S == "R") {
            N = t;
            update();
        } else {
            M = t;
            update();
        }

        if (N == 1) {
            cout << "C 1\n";
            cout.flush();
            M = 1;
            update();
        } else if (M == 1) {
            cout << "R 1\n";
            cout.flush();
            N = 1;
            update();
        } else if (palki % 2 == 0) {
            if (N == 2 and M == 2)
                break;
            else if (N == 3 and M == 3)
                break;
            else if (N != 2) {
                cout << "R 2\n";
                cout.flush();
                N = 2;
                update();
            } else {
                cout << "C 2\n";
                cout.flush();
                M = 2;
                update();
            }
        } else { // palki % 2 == 1
            if (N != 2) {
                cout << "R 2\n";
                cout.flush();
                N = 2;
                update();
            } else {
                cout << "C 2\n";
                cout.flush();
                M = 2;
                update();
            }
        }
    }

    return 0;
}

void update() {
    palki = N - 1 + M - 1;
    return;
}
