// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    h[MAX_SIZE];
lli M;
lli ans;

void solve();
bool f(lli);
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> h[i];
    cin >> M;
    
    if (M < N) {
        cout << "-1\n";
        return;
    }

    ans = bs();
    cout << ans << '\n';
    return;
}

bool f(lli x) {
    lli cnt = 0LL;
    for (int i = 0; i < (int)N; ++i)
        cnt += (h[i] + x - 1LL) / x;
    return (cnt <= M);
}

lli bs() {
    lli l = 0LL,
        r = (lli)1e10;
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        if (f(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}
