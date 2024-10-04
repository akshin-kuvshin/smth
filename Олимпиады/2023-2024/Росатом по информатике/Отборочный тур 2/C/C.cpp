// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e2 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N,
    A[MAX_SIZE];
vector<lli> sh;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    for (int k = 0; k + 1 < (int)N; ++k) {
        plli m = {INF, -1};
        for (int i = k; i < (int)N; ++i)
            m = min(m, mp(A[i], (lli)i));
        
        while ((lli)k < m.second)
            if (m.second - (lli)k == 1LL and k == 0LL) {
                sort(A + m.second - 1LL, A + m.second + 2LL);
                sh.pb(m.second);
                --m.second;
            } else {
                sort(A + (m.second - 1LL) - 1LL, A + (m.second - 1LL) + 2LL);
                sh.pb(m.second - 1LL);
                m.second -= 2LL;
            }
    }
    
    cout << sh.size() << '\n';
    for (lli elem : sh)
        cout << (elem + 1LL) << ' ';
    cout << '\n';
    return;
}
