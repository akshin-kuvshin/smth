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

    // check for impossible
    if (N < 50LL) { // раньше здесь было "N < 40", но не уверен, что это повлияло
        int ptr = (int)N - 1;
        if ((1LL << ptr) < K) {
            cout << "-1\n";
            return;
        }
    }

    // so, now it is possible
    vector<lli> P(N);
    lli l_ind = 0LL,
        r_ind = N - 1LL,
        r_ptr = N - 1LL,
        cur = 1LL;
    while (r_ptr > 50LL) { // раньше здесь было "r_ptr >= 40", и это повлияло
        P[l_ind++] = cur++;
        --r_ptr;
    }
    lli l = 1LL,
        r = (1LL << (int)r_ptr) + 1LL;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        if (K < m) {
            P[l_ind++] = cur++;
            r = m;
        } else { // m <= K
            P[r_ind--] = cur++;
            l = m;
        }
    }
    P[l_ind] = cur;
    for (int i = 0; i < (int)N; ++i)
        cout << P[i] << ' ';
    cout << '\n';
    return;
}
