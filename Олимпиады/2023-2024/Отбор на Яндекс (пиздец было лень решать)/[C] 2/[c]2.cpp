// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

lli A,
    B,
    X;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> A >> B;

    while (A != B) {
        if (A < B) {
            X += B / A;
            B %= A;

            if (!B) {
                --X;
                B += A;
            }
        } else {
            X += A / B;
            A %= B;

            if (!A) {
                --X;
                A += B;
            }
        }
    }

    cout << X << '\n';
    return;
}
