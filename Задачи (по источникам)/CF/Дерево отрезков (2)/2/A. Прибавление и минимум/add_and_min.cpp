// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e5,
          BIG = (lli)1e18;



class segtree {
private:
    lli tree[MAX_SIZE];
    lli op[MAX_SIZE];
    lli size;

    void add(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] += val;
            tree[x] += val;
            return;
        }

        lli mid = (lx + rx) >> 1;
        add(l, r, val, 2LL * x + 1LL, lx, mid);
        add(l, r, val, 2LL * x + 2LL, mid, rx);
        // Изначально здесь забыл добавить op[x], но pashka из будущего в разборе кода подсказал это.)
        tree[x] = min(tree[2LL * x + 1LL], tree[2LL * x + 2LL]) + op[x];
        return;
    }

    lli segmin(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return BIG;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        lli min_l = segmin(l, r, 2LL * x + 1LL, lx, mid),
            min_r = segmin(l, r, 2LL * x + 2LL, mid, rx);
        return min(min_l, min_r) + op[x];
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

    void add(lli l, lli r, lli val) {
        add(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli segmin(lli l, lli r) {
        return segmin(l, r, 0LL, 0LL, size);
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
            st.add(l, r, val);
        } else { // cmd == 2LL
            lli l,
                r;
            cin >> l >> r;
            cout << st.segmin(l, r) << '\n';
        }
    }
    
    return;
}
