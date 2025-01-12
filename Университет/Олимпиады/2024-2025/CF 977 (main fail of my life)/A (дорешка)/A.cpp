// author: Danila "akshin_" Axyonov

#include <iostream>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
lli N;
multiset<lli> S;

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
    S.clear();

    cin >> N;
    for (int _ = 0; _ < (int)N; ++_) {
        lli num;
        cin >> num;
        S.insert(num);
    }

    while ((lli)S.size() > 1LL) {
        lli x1 = *S.begin();
        S.erase(S.begin());
        lli x2 = *S.begin();
        S.erase(S.begin());
        S.insert((x1 + x2) >> 1);
    }
    
    cout << *S.begin() << '\n';
    return;
}
