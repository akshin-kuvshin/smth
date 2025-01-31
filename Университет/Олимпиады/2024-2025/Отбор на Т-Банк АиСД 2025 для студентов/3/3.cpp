// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

struct tree {
    lli h;
    lli a;
    lli t;
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<tree> f(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> f[i].h;
    for (int i = 0; i < (int)n; ++i)
        cin >> f[i].a;
    for (int i = 0; i < (int)n; ++i)
        cin >> f[i].t;
    sort(f.begin(), f.end(), [](tree t1, tree t2) {
        return t1.t > t2.t;
    });

    lli cur_t = 0LL,
        after_max_t = INF, // in fact, min_bad_t
        prev_h = f[0].h,
        prev_a = f[0].a;
    for (int i = 1; i < (int)n; ++i) {
        lli cur_h = f[i].h + cur_t * f[i].a,
            cur_a = f[i].a;
        if (prev_a == cur_a) {
            if (prev_h >= cur_h) {
                cout << "-1\n";
                return;
            }
        } else if (prev_a < cur_a) {
            lli dt = 0LL;
            if (prev_h >= cur_h)
                dt = (prev_h - cur_h) / (cur_a - prev_a) + 1LL;
            cur_h += dt * cur_a;
            cur_t += dt;
        } else { // prev_a > cur_a
            if (prev_h >= cur_h) {
                cout << "-1\n";
                return;
            }
            // now prev_h < cur_h
            lli bad_dt = (cur_h - prev_h + prev_a - cur_a - 1LL) / (prev_a - cur_a);
            after_max_t = min(after_max_t, cur_t + bad_dt);
        }
        prev_h = cur_h;
        prev_a = cur_a;
    }
    
    cout << (cur_t < after_max_t ? cur_t : -1LL) << '\n';
    return;
}
