// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
lli N,
    M;
vector<bool> A,
             B;
char tmp;
lli ans;

void solve();
lli bs();
bool f(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    A.resize(N);
    B.resize(M);
    for (int i = 0; i < (int)N; ++i) {
        cin >> tmp;
        A[i] = (tmp == '1' ? true : false);
    }
    for (int i = 0; i < (int)M; ++i) {
        cin >> tmp;
        B[i] = (tmp == '1' ? true : false);
    }

    ans = bs();
    cout << ans << '\n';
    return;
}

lli bs() {
    lli l = 0LL,
        r = N + 1LL;
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        if (f(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}

bool f(lli x) {
    if (x > M)
        return false;

    vector<bool> pref(x);
    copy(A.begin(), A.begin() + x, pref.begin());
    
    int i = 0,
        j = 0;
    while (i < (int)x and j < (int)M) {
        if (pref[i] == B[j]) {
            ++i; ++j;
        } else
            ++j;
    }

    return (i == (int)x);
}
