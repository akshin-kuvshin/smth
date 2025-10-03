// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define x                   first
#define y                   second

lli sgn(lli num);

struct tangle {
    lli cr_pr,
        sc_pr;
    
    tangle(plli v): cr_pr(v.y), sc_pr(v.x) {}
    
    bool operator<(tangle t) {
        if (not this->sc_pr and not t.sc_pr)
            return sgn(this->cr_pr) < sgn(t.cr_pr);
        if (not this->sc_pr)
            return sgn(this->cr_pr) == -1LL;
        if (not t.sc_pr)
            return sgn(t.sc_pr) == 1LL;
        return this->cr_pr * t.sc_pr < t.cr_pr * this->sc_pr;
    }
    
    bool operator==(tangle t) {
        if (not this->sc_pr and not t.sc_pr)
            return sgn(this->cr_pr) == sgn(t.cr_pr);
        if (not this->sc_pr or not t.sc_pr)
            return false;
        return this->cr_pr * t.sc_pr == t.cr_pr * this->sc_pr;
    }
};

void solve();
plli make_vector(plli a, plli b);
lli get_cr_pr(plli u, plli v); // [u, v]
lli get_sc_pr(plli u, plli v); // (u, v)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<plli> a_tmp(n);
    for (plli& a_tmpi : a_tmp)
        cin >> a_tmpi.x >> a_tmpi.y;
    
    lli m;
    cin >> m;
    vector<plli> b(m);
    for (plli& bi : b)
        cin >> bi.x >> bi.y;
    
    int base_index = (int)(min_element(a_tmp.begin(), a_tmp.end()) - a_tmp.begin());
    plli base_dot = a_tmp[base_index];
    vector<plli> a;
    for (int i = base_index - 1; i >= 0; --i)
        a.pb(a_tmp[i]);
    for (int i = (int)n - 1; i > base_index; --i)
        a.pb(a_tmp[i]);
    
    vector<tangle> a_tangles;
    for (plli ai : a) {
        plli base_ai = make_vector(base_dot, ai);
        a_tangles.pb(tangle(base_ai));
    }
    
    for (plli bi : b) {
        if (bi == base_dot) {
            cout << "NO\n";
            return;
        }    
        
        plli base_bi = make_vector(base_dot, bi);
        tangle base_bi_tangle(base_bi);
        
        int upper_index = (int)(lower_bound(a_tangles.begin(), a_tangles.end(), base_bi_tangle) - a_tangles.begin());
        if (not upper_index or upper_index == (int)n - 1) {
            cout << "NO\n";
            return;
        }
        if (upper_index == (int)n - 2 and base_bi_tangle == a_tangles.back()) {
            cout << "NO\n";
            return;
        }
        
        if (base_bi_tangle == a_tangles[upper_index]) {
            plli base_aui = make_vector(base_dot, a[upper_index]); // aui - a_upper_index
            if (get_sc_pr(base_bi, base_bi) >= get_sc_pr(base_aui, base_aui)) {
                cout << "NO\n";
                return;
            }
        } else { // base_bi_tangle < a_tangles[upper_index]
            int lower_index = upper_index - 1;
            plli lower_upper = make_vector(a[lower_index], a[upper_index]),
                 lower_bi = make_vector(a[lower_index], bi);
            if (get_cr_pr(lower_upper, lower_bi) <= 0LL) {
                cout << "NO\n";
                return;
            }
        }
    }
    
    cout << "YES\n";
    return;
}

plli make_vector(plli a, plli b) {
    return mp(b.x - a.x, b.y - a.y);
}

lli get_cr_pr(plli u, plli v) {
    return u.x * v.y - v.x * u.y;
}

lli get_sc_pr(plli u, plli v) {
    return u.x * v.x + u.y * v.y;
}

lli sgn(lli num) {
    if (num < 0LL)
        return -1LL;
    if (not num)
        return 0LL;
    return 1LL;
}

