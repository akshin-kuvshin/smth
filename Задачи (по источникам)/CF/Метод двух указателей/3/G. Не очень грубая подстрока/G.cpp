// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e6 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N;
char S[MAX_SIZE];
lli a,
    b,
    r; // rudeness
lli C;
lli ans = -INF;

void solve();
void add(char);
void remove(char);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> C;
    for (int i = 0; i < (int)N; ++i)
        cin >> S[i];
    
    lli L = 0LL;
    for (lli R = 0LL; R < N; ++R) {
        add(S[R]);
        while (r > C)
            remove(S[L++]);
        ans = max(ans, R - L + 1LL);
    }
    
    cout << ans << '\n';
    return;
}

void add(char c) {
    if (c == 'a')
        ++a;
    else if (c == 'b') {
        ++b;
        r += a;
    }
    return;
}

void remove(char c) {
    if (c == 'a') {
        --a;
        r -= b;
    } else if (c == 'b')
        --b;
    return;
}
