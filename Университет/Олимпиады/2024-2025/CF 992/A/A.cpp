// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli N,
        K;
    cin >> N >> K;
    vector<lli> A(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    unordered_map<lli, lli> mod_cnt;
    for (int i = 0; i < (int)N; ++i)
        ++mod_cnt[A[i] % K];
    
    for (const auto [mod, cnt] : mod_cnt)
        if (cnt < 2LL) {
            cout << "YES\n";
            for (int i = 0; i < (int)N; ++i)
                if (A[i] % K == mod) {
                    cout << ++i << '\n';
                    break;
                }
            return;
        }
    cout << "NO\n";
    return;
}
