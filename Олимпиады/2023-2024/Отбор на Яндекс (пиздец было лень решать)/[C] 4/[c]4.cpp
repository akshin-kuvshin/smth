// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)2e3;

lli Q;
lli N;
char S[MAX_SIZE + 5LL];
bool bad_flag;

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
    for (int i = 0; i < (int)N; ++i)
        cin >> S[i];
    
    for (int l1 = 1; l1 <= (int)N; ++l1) {
        bad_flag = false;
        for (int i = 0, j = l1; i < l1 and j < N; ++i, ++j) {
            if (S[i] < S[j]) {
                cout << "Yes\n";
                return;
            }
            if (S[i] > S[j]) {
                bad_flag = true;
                break;
            }
        }
        if (!bad_flag and l1 < N - l1) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
}
