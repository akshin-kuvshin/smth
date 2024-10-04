// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

lli x1,
    y1,
    x2,
    y2;
bool A[(lli)2e3 + 5LL][(lli)2e3 + 5LL];
lli cnt;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    for (int _ = 0; _ < 4; ++_) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1000LL,
        y1 += 1000LL,
        x2 += 1000LL,
        y2 += 1000LL;

        for (int i = (int)x1; i < (int)x2; ++i)
            for (int j = (int)y1; j < (int)y2; ++j)
                A[i][j] = true;
    }

    for (int i = 0; i <= 2000; ++i)
        for (int j = 0; j <= 2000; ++j)
            if (A[i][j])
                ++cnt;
    cout << cnt << '\n';
    return;
}
