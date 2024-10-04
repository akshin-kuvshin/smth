// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e5;

lli x,
    y,
    a,
    b,
    c,
    p[MAX_SIZE + 5LL],
    q[MAX_SIZE + 5LL],
    r[MAX_SIZE + 5LL];
vector<lli> to_eat;
lli answer;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> x >> y >> a >> b >> c;
    for (int i = 0; i < (int)a; ++i)
        cin >> p[i];
    for (int j = 0; j < (int)b; ++j)
        cin >> q[j];
    for (int k = 0; k < (int)c; ++k)
        cin >> r[k];
    
    sort(p, p + a);
    sort(q, q + b);
    sort(r, r + c);

    for (int cnt = 0, i = (int)a - 1; cnt < (int)x and i >= 0; ++cnt, --i)
        to_eat.push_back(p[i]);
    for (int cnt = 0, j = (int)b - 1; cnt < (int)y and j >= 0; ++cnt, --j)
        to_eat.push_back(q[j]);
    sort(to_eat.begin(), to_eat.end());

    for (int ind = 0, k = (int)c - 1;
         ind < (int)to_eat.size() and k >= 0 and to_eat[ind] < r[k];
         ++ind, --k) {
        to_eat[ind] = r[k];
    }

    for (lli elem : to_eat)
        answer += elem;
    cout << answer << '\n';
    return;
}
