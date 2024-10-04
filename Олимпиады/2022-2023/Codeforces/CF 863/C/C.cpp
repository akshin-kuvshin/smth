#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 200000LL;

lli Q;
lli N,
    B[MAX_SIZE + 5LL];
lli previous;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N;
    --N;
    for (int i = 0; i < (int)N; ++i)
        cin >> B[i];
    
    previous = B[0];
    for (int i = 0; i + 1 < (int)N; ++i) {
        cout << previous << ' ';

        // Нам нельзя приходить к случаю previous > B[i]
        if (previous < B[i]) {
            previous = B[i];
        } else { // previous == B[i]
            if (B[i] < B[i + 1]) { // здесь можно ставить любое целое x из отрезка [0; B[i]]
                previous = 0LL;
            } else if (B[i] == B[i + 1]) {
                previous = B[i];
            } else { // B[i] > B[i + 1]
                previous = B[i + 1];
            }
        }
    }
    cout << previous << ' ' << B[N - 1LL] << '\n';

    return;
}
