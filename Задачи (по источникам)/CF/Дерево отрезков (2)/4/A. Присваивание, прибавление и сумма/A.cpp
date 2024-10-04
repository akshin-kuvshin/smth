// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define left                (2LL * x + 1LL)
#define right               (2LL * x + 2LL)

#define NO_EQ               -1LL







class segtree {
private:
    vector<lli> tree;
    vector<lli> d;
    vector<lli> eq;
    lli size;

    void propagate(lli x, lli lx, lli rx) {
        lli len2 = (rx - lx) >> 1;

        if (eq[x] == NO_EQ) {
            d[left] += d[x];
            tree[left] += d[x] * len2;

            d[right] += d[x];
            tree[right] += d[x] * len2;
        } else { // eq[x] != NO_EQ
            eq[left] = eq[x];
            d[left] = d[x];
            tree[left] = (eq[left] + d[left]) * len2;

            eq[right] = eq[x];
            d[right] = d[x];
            tree[right] = (eq[right] + d[right]) * len2;
        }

        eq[x] = NO_EQ;
        d[x] = 0LL;
        tree[x] = tree[left] + tree[right];

        return;
    }

    void set(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            eq[x] = val;
            d[x] = 0LL;
            tree[x] = eq[x] * (rx - lx);
            return;
        }

        propagate(x, lx, rx);

        lli mid = (lx + rx) >> 1;
        set(l, r, val, left, lx, mid);
        set(l, r, val, right, mid, rx);
        tree[x] = tree[left] + tree[right];
        return;
    }

    void add(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            d[x] += val;
            tree[x] += val * (rx - lx);
            return;
        }

        propagate(x, lx, rx);

        lli mid = (lx + rx) >> 1;
        add(l, r, val, left, lx, mid);
        add(l, r, val, right, mid, rx);
        tree[x] = tree[left] + tree[right];
        return;
    }

    lli sum(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return 0LL;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli _l = max(l, lx),
            _r = min(r, rx);
        
        if (eq[x] != NO_EQ)
            return (eq[x] + d[x]) * (_r - _l);

        lli mid = (lx + rx) >> 1;
        return sum(l, r, left, lx, mid) +
               sum(l, r, right, mid, rx) +
               d[x] * (_r - _l);
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        tree.assign(2LL * size - 1LL, 0LL);
        d.assign(2LL * size - 1LL, 0LL);
        eq.assign(2LL * size - 1LL, NO_EQ);
        return;
    }

    void set(lli l, lli r, lli val) {
        set(l, r, val, 0LL, 0LL, size);
        return;
    }

    void add(lli l, lli r, lli val) {
        add(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli sum(lli l, lli r) {
        return sum(l, r, 0LL, 0LL, size);
    }
};







lli N;
segtree st;
lli Q,
    cmd,
    l,
    r,
    val;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    st.init(N);

    cin >> Q;
    while (Q--) {
        cin >> cmd;
        if (cmd == 1LL) {
            cin >> l >> r >> val;
            st.set(l, r, val);
        } else if (cmd == 2LL) {
            cin >> l >> r >> val;
            st.add(l, r, val);
        } else { // cmd == 3LL
            cin >> l >> r;
            cout << st.sum(l, r) << '\n';
        }
    }
    
    return;
}
