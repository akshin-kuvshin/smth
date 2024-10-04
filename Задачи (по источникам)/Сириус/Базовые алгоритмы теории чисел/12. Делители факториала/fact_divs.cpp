// author: Danila "akshin_" Aksionov

#include <iostream>
#include <map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N;
map<lli, lli> m;
lli ans;

void solve();
void factorize(lli, map<lli, lli>&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (lli i = 1LL; i <= N; ++i)
        factorize(i, m);
    
    ans = 1LL;
    for (plli p : m)
        ans *= (p.second + 1LL);
    cout << ans << '\n';
    return;
}

void factorize(lli num, map<lli, lli> &divs) {
    for (lli d = 2LL; d * d <= num; ++d)
        while (num % d == 0LL) {
            num /= d;
            ++divs[d];
        }
    if (num > 1LL)
        ++divs[num];
    return;
}
