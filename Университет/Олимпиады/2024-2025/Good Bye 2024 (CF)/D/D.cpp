// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define val                 first
#define index               second

const lli MOD = 998'244'353LL;
const size_t INF = (size_t)1e18 + 1ULL;

void solve();
vector<size_t> get_inds(const vector<pair<lli, size_t>>&);
lli divide(lli, lli);
lli mod_pow(lli, lli);

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
    size_t n,
           q;
    cin >> n >> q;
    vector<pair<lli, size_t>> a(n),
                              b(n);
    for (size_t i = 0ULL; i < n; ++i) {
        cin >> a[i].val;
        a[i].index = i;
    }
    for (size_t i = 0ULL; i < n; ++i) {
        cin >> b[i].val;
        b[i].index = i;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<size_t> ind_a = get_inds(a),
                   ind_b = get_inds(b);
    
    lli res = 1LL;
    for (size_t i = 0ULL; i < n; ++i)
        res = (res * min(a[i].val, b[i].val)) % MOD;
    cout << res << ' ';
    
    while (q--) {
        lli op;
        size_t x;
        cin >> op >> x;
        --x;

        if (op == 1LL) { // ++a[x]
            size_t i = ind_a[x];
            size_t j = upper_bound(a.begin(), a.end(), mp(a[i].val, INF)) - a.begin();
            --j;
            lli prev = min(a[j].val, b[j].val);
            ++a[j].val;
            res = (divide(res, prev) * min(a[j].val, b[j].val)) % MOD;
            swap(a[i].index, a[j].index);
            swap(ind_a[a[i].index], ind_a[a[j].index]);
        } else { // op == 2LL // ++b[x]
            size_t i = ind_b[x];
            size_t j = upper_bound(b.begin(), b.end(), mp(b[i].val, INF)) - b.begin();
            --j;
            lli prev = min(a[j].val, b[j].val);
            ++b[j].val;
            res = (divide(res, prev) * min(a[j].val, b[j].val)) % MOD;
            swap(b[i].index, b[j].index);
            swap(ind_b[b[i].index], ind_b[b[j].index]);
        }

        cout << res << ' ';
    }
    cout << '\n';
    return;
}

vector<size_t> get_inds(const vector<pair<lli, size_t>> &arr) {
    vector<size_t> ind(arr.size());
    for (size_t i = 0ULL; i < arr.size(); ++i)
        ind[arr[i].index] = i;
    return ind;
}

lli divide(lli up, lli down) {
    lli res = mod_pow(down, MOD - 2LL);
    return (res * up) % MOD;
}

lli mod_pow(lli base, lli ptr) {
    if (ptr == 0LL) return 1LL;
    if (ptr & 1LL) return (base * mod_pow(base, --ptr)) % MOD;
    lli half = mod_pow(base, ptr >> 1);
    return (half * half) % MOD;
}
