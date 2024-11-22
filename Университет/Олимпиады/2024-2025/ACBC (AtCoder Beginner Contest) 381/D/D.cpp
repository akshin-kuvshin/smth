// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <map>
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
    vector<lli> A(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    if (N == 1LL) {
        cout << "0\n";
        return;
    }
    // now N >= 2

    // for even b and e
    map<lli, lli> m;
    lli ans = 0LL;
    lli b = 0LL;
    for (lli e = 2LL; e <= N; e += 2LL) {
        if (A[e - 2LL] != A[e - 1LL]) {
            m.clear();
            b = e;
            continue;
        }

        lli cur = A[e - 1LL]; // also can write ... = A[e - 2LL];
        m[cur] += 2LL;
        while (m[cur] > 2LL) {
            m[A[b]] -= 2LL;
            b += 2LL;
        }

        ans = max(ans, e - b);
    }

    // for odd b and e
    // (only difference is that on start b = 1 and e = 3)
    m.clear();
    b = 1LL;
    for (lli e = 3LL; e <= N; e += 2LL) {
        if (A[e - 2LL] != A[e - 1LL]) {
            m.clear();
            b = e;
            continue;
        }

        lli cur = A[e - 1LL]; // also can write ... = A[e - 2LL];
        m[cur] += 2LL;
        while (m[cur] > 2LL) {
            m[A[b]] -= 2LL;
            b += 2LL;
        }

        ans = max(ans, e - b);
    }

    cout << ans << '\n';
    return;
}
