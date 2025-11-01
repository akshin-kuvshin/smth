// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
typedef long long int lli;
using namespace std;

#define mx ((lx + rx) / 2LL)
#define x1 (2LL * x + 1LL)
#define x2 (2LL * x + 2LL)

const int SZ = 20;

class segtree {
private:
    vector<lli> tree;
    vector<bool> is_xor;
    lli size;
    int bit;
    
    void build(const vector<lli>& a, lli n, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = ((lx < n) ? (bool)(a[lx] & (1LL << bit)) : 0LL);
            return;
        }
        build(a, n, x1, lx, mx);
        build(a, n, x2, mx, rx);
        tree[x] = tree[x1] + tree[x2];
    }
    
    void apply_xor(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            if (val & (1LL << bit))
                is_xor[x] = not is_xor[x];
            return;
        }
        
        apply_xor(l, r, val, x1, lx, mx);
        apply_xor(l, r, val, x2, mx, rx);
        
        tree[x] = 0LL;
        tree[x] += (is_xor[x1] ? (mx - lx - tree[x1]) : tree[x1]);
        tree[x] += (is_xor[x2] ? (rx - mx - tree[x2]) : tree[x2]);
    }
    
    lli sum(lli l, lli r, bool cum_xor, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return 0LL;
        cum_xor = cum_xor xor is_xor[x];
        if (l <= lx and rx <= r)
            return (cum_xor ? (rx - lx - tree[x]) : tree[x]);
        return sum(l, r, cum_xor, x1, lx, mx)
             + sum(l, r, cum_xor, x2, mx, rx);
    }

public:
    void init(const vector<lli>& a, lli n, int i) {
        size = 1LL;
        while (size < n)
            size *= 2LL;
        bit = i;
        tree.resize(2LL * size - 1LL);
        is_xor.assign(2LL * size - 1LL, false);
        build(a, n, 0LL, 0LL, size);
    }
    
    void apply_xor(lli l, lli r, lli val) {
        apply_xor(l, r, val, 0LL, 0LL, size);
    }
    
    lli sum(lli l, lli r) {
        return sum(l, r, false, 0LL, 0LL, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli& ai : a)
        cin >> ai;
    
    segtree st[SZ];
    for (int i = 0; i < SZ; ++i)
        st[i].init(a, n, i);
    
    lli m;
    cin >> m;
    while (m--) {
        lli cmd;
        cin >> cmd;
        if (cmd == 1LL) {
            lli l,
                r;
            cin >> l >> r;
            --l;
            
            lli res = 0LL;
            for (int i = 0; i < SZ; ++i)
                res += st[i].sum(l, r) * (1LL << i);
            cout << res << '\n';
        } else { // cmd == 2LL
            lli l,
                r,
                val;
            cin >> l >> r >> val;
            --l;
            
            for (int i = 0; i < SZ; ++i)
                st[i].apply_xor(l, r, val);
        }
    }
    
    return 0;
}
