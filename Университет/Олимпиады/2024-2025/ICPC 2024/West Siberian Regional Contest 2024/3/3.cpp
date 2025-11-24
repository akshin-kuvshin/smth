// author: Danila "akshin_" Axyonov

#include <iostream>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
void check(lli, lli, lli, lli, set<lli>&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;

    set<lli> S;
    check(w1, h1, w2, h2, S);
    check(w1, h1, h2, w2, S);
    for (lli p : S)
        cout << p << ' ';
    cout << '\n';
    return;
}

void check(lli w1, lli h1, lli w2, lli h2, set<lli> &S) {
    if (w1 < w2 or h1 < h2)
        return;
    if (w1 == w2 and h1 == h2) {
        S.insert(0LL);
        return;
    }
    if (w1 == w2) { // and h1 != h2
        S.insert(2LL * (w1 + h1 - h2));
        S.insert(4LL * w1 + 2LL * (h1 - h2));
        return;
    }
    if (h1 == h2) {
        S.insert(2LL * (h1 + w1 - w2));
        S.insert(4LL * h1 + 2LL * (w1 - w2));
        return;
    }
    lli p = 2LL * (w1 + h1);
    S.insert(p);
    S.insert(p + 2LL * w2);
    S.insert(p + 2LL * h2);
    return;
}
