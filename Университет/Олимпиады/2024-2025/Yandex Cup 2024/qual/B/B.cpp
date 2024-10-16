// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define mmin                -1LL
#define mmax                1LL
#define DOWN                false
#define UP                  true

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)2e5 + 5LL;

lli Q;
lli N,
    H[MAX_SIZE],
    flag[MAX_SIZE];
vector<lli> lens;
lli ans;

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
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> H[i];
    
    if (N < 3LL) {
        cout << "0\n";
        return;
    }

    fill(flag, flag + N, 0LL);
    if (H[0] < H[1])
        flag[0] = mmin;
    for (int i = 1; i + 1 < (int)N; ++i)
        if (H[i - 1] < H[i] and H[i] > H[i + 1])
            flag[i] = mmax;
        else if (H[i - 1] > H[i] and H[i] < H[i + 1])
            flag[i] = mmin;
    if (H[(int)N - 2] > H[(int)N - 1])
        H[(int)N - 1] = mmin;
    
    lens.clear();
    lli len = 0LL;
    for (int i = 0; i < (int)N; ++i)
        if (flag[i] == mmin) {
            lens.pb(len + 1LL);
            len = 1LL;
        } else if (flag[i] == mmax) {
            lens.pb(len);
            len = 0LL;
        } else // flag[i] == 0LL
            ++len;
    lens.erase(lens.begin());
    lens.pb(len);

    /* for (lli l : lens)
        cout << l << ' ';
    cout << '\n';
    return; */
    
    ans = 0LL;
    lli sz = (lli)lens.size();
    for (int i = 0; i + 1 < (int)sz; i += 2)
        ans += lens[i] * lens[i + 1];
    cout << ans << '\n';
    return;
}
