// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e5,
          NEUTRAL = ((1LL << 30) - 1LL); // нейтральный элемент для операции битового AND (состоит из единиц)



class segtree {
private:
    lli tree[MAX_SIZE];
    lli op[MAX_SIZE];
    lli size;

    void or_eq_each(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] |= val;
            tree[x] |= val;
            return;
        }

        lli mid = (lx + rx) >> 1;
        or_eq_each(l, r, val, 2LL * x + 1LL, lx, mid);
        or_eq_each(l, r, val, 2LL * x + 2LL, mid, rx);
        tree[x] = (tree[2LL * x + 1LL] & tree[2LL * x + 2LL]) | op[x];
        return;
    }

    lli seg_and(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return NEUTRAL;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        lli seg_and_l = seg_and(l, r, 2LL * x + 1LL, lx, mid),
            seg_and_r = seg_and(l, r, 2LL * x + 2LL, mid, rx);
        return (seg_and_l & seg_and_r) | op[x];
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        fill(tree, tree + 2LL * size, 0LL);
        fill(op, op + 2LL * size, 0LL);
        return;
    }

    void or_eq_each(lli l, lli r, lli val) {
        or_eq_each(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli seg_and(lli l, lli r) {
        return seg_and(l, r, 0LL, 0LL, size);
    }
};



lli N;
segtree st;
lli Q,
    cmd;



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
            lli l,
                r,
                val;
            cin >> l >> r >> val;
            st.or_eq_each(l, r, val);
        } else { // cmd == 2LL
            lli l,
                r;
            cin >> l >> r;
            cout << st.seg_and(l, r) << '\n';
        }
    }
    
    return;
}
