// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e5;

class segtree {
private:
    lli tree[MAX_SIZE];
    lli size;

    void set_max(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            tree[x] = max(tree[x], val);
            return;
        }

        lli mid = (lx + rx) >> 1;
        set_max(l, r, val, 2LL * x + 1LL, lx, mid);
        set_max(l, r, val, 2LL * x + 2LL, mid, rx);
        return;
    }
    
    lli get(lli i, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        if (i < mid)
            return max(get(i, 2LL * x + 1LL, lx, mid), tree[x]);
        return max(get(i, 2LL * x + 2LL, mid, rx), tree[x]);
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        fill(tree, tree + (size << 1), 0LL);
        return;
    }

    void set_max(lli l, lli r, lli val) {
        set_max(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli get(lli i) {
        return get(i, 0LL, 0LL, size);
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
            st.set_max(l, r, val);
        } else { // cmd == 2LL
            lli i;
            cin >> i;
            cout << st.get(i) << '\n';
        }
    }
    
    return;
}
