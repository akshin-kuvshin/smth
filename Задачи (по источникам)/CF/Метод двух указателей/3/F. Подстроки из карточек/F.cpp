// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli LITTLE_MAX_SIZE = 256LL,
          BIG_MAX_SIZE = (lli)1e5 + 5LL;

lli N;
char S[BIG_MAX_SIZE];
lli cnt[LITTLE_MAX_SIZE];
lli M;
lli cards[LITTLE_MAX_SIZE];
bool good = true;
lli ans;

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
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> S[i];
    while (M--) {
        char c;
        cin >> c;
        ++cards[c];
    }

    lli L = 0LL;
    for (lli R = 0LL; R < N; ++R) {
        add(S[R]);
        while (not good)
            remove(S[L++]);
        ans += R - L + 1LL;
    }
    
    cout << ans << '\n';
    return;
}

void add(char c) {
    ++cnt[c];
    if (cnt[c] > cards[c]) // cnt[c] == cards[c] + 1
        good = false;
    return;
}

void remove(char c) {
    --cnt[c];
    if (cnt[c] == cards[c])
        good = true;
    return;
}
