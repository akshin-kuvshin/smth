// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

const lli N = 90LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // h[i] = минимальное кол-во вершин, чтобы высота дерева была i.
    vector<lli> h(N);
    h[0] = 0LL;
    h[1] = 1LL;
    for (int i = 2; i < (int)N; ++i)
        h[i] = h[i - 2] + h[i - 1] + 1LL;
    
    lli _n;
    cin >> _n;

    lli l = 0LL,
        r = N;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        if (h[m] <= _n)
            l = m;
        else // h[m] > _n
            r = m;
    }
    
    cout << l << '\n';
    return 0;
}
