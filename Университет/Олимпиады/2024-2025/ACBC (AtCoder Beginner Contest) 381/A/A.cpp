// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli N;
    cin >> N;
    vector<char> S(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> S[i];
    
    if (N % 2LL == 0LL) {
        cout << "No\n";
        return;
    }
    
    for (int i = 0; i < ((int)N >> 1); ++i)
        if (S[i] != '1') {
            cout << "No\n";
            return;
        }
    if (S[(int)N >> 1] != '/') {
        cout << "No\n";
        return;
    }
    for (int i = ((int)N >> 1) + 1; i < (int)N; ++i)
        if (S[i] != '2') {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
    return;
}
