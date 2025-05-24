// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> h(n);

    h.front() = h.back() = 100LL;

    lli prev = 0LL;
    for (int i = 1; i < (int)n - 1; ++i) {
        cout << "? 0 " << i << endl;

        lli v;
        cin >> v;

        lli dv = v - prev;
        for (int j = i - 1; j >= 0 and dv; --j) {
            if (h[j] <= h[i])
                continue;
            lli x = min(dv, (h[j] - h[i]) * (lli)(i - j));
            h[i] += x / (lli)(i - j);
            dv -= x;
        }

        prev = v;
    }

    cout << '!';
    for (lli hi : h)
        cout << ' ' << hi;
    cout << endl;
    
    return;
}
