// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e6 + 5LL,
          INF = (lli)1e18 + 1LL;

class segtree {
private:
    vector<pair<lli, plli>> tree; // min - max
    lli size;

    void build(lli *A, lli orig_sz, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < orig_sz)
                tree[x] = mp(A[lx], mp(A[lx], lx));
            else // lx >= orig_sz
                tree[x] = {INF, {-INF, -1LL}};
            return;
        }

        lli mid = (lx + rx) >> 1;
        build(A, orig_sz, 2LL * x + 1LL, lx, mid);
        build(A, orig_sz, 2LL * x + 2LL, mid, rx);
        tree[x] = mp(
            min(tree[2LL * x + 1LL].first, tree[2LL * x + 2LL].first),
            max(tree[2LL * x + 1LL].second, tree[2LL * x + 2LL].second)
        );
        return;
    }

    pair<lli, plli> get_minmax(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return {INF, {-INF, -1LL}};
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        pair<lli, plli> res_l = get_minmax(l, r, 2LL * x + 1LL, lx, mid),
                        res_r = get_minmax(l, r, 2LL * x + 2LL, mid, rx);
        return mp(
            min(res_l.first, res_r.first),
            max(res_l.second, res_r.second)
        );
    }

public:
    void init(lli *A, lli orig_sz) {
        size = 1LL;
        while (size < orig_sz)
            size <<= 1;
        tree.resize(2LL * size - 1LL);
        build(A, orig_sz, 0LL, 0LL, size);
        return;
    }

    pair<lli, plli> get_minmax(lli l, lli r) {
        return get_minmax(l, r, 0LL, 0LL, size);
    }
};

lli N,
    A[MAX_SIZE];
lli pref[MAX_SIZE];
segtree st;

lli Q;

void solve();
lli res(lli, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> Q;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        pref[i + 1] = pref[i] ^ A[i];
    }
    st.init(A, N);
    
    while (Q--) {
        lli l,
            r,
            x;
        cin >> l >> r >> x;
        --l;
        cout << res(l, r, x) << '\n';
    }
    
    return;
}

lli res(lli l, lli r, lli x) {
    if (l >= r)
        return 0LL;

    pair<lli, plli> minmax = st.get_minmax(l, r);

    if (x < minmax.first)
        return 0LL;
    if (minmax.second.first <= x)
        return pref[r] ^ pref[l];
    
    return res(l, minmax.second.second, x) ^ res(minmax.second.second + 1LL, r, x);
}
