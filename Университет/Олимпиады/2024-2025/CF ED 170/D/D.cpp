// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N_max = (lli)2e6 + 5LL,
          M_max = (lli)5e3 + 5LL;

lli N,
    M,
    r[N_max];
lli ans;

void solve();
lli bs();
bool f(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> r[i];
    
    ans = bs();
    cout << ans << '\n';
    
    return;
}

lli bs() {
    lli l = 0LL,
        r = N + 1LL;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        if (f(m))
            l = m;
        else
            r = m;
    }
    return l;
}

bool f(lli x) { // Можно ли набрать хотя бы x проверок
    // хз как сделать
    // честно говоря, вообще не уверен, что это решается бин. поиском
    return false; // Заглушка
}
