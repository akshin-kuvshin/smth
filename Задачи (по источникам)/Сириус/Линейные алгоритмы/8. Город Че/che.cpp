// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)3e5 + 5LL;

lli N,
    d[MAX_SIZE],
    k;
lli l,
    r,
    cnt;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> k;
    for (int i = 0; i < (int)N; ++i)
        cin >> d[i];
    
    while (r < N) {
        if (d[r] - d[l] <= k)
            ++r;
        else { // d[r] - d[l] > k
            cnt += (N - r);
            ++l;
        } 
    }
    
    cout << cnt << '\n';
    return;
}
