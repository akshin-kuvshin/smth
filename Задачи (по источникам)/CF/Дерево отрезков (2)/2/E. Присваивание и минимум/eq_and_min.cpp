// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
#define NO_EQ -1LL
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e5,
          BIG = (lli)1e10;

class segtree {
private:
    lli tree[MAX_SIZE];
    lli op[MAX_SIZE];
    lli size;

    void propagate(lli x) {
        lli _left = 2LL * x + 1LL,
            _right = 2LL * x + 2LL;
        
        op[_left] = op[x];
        tree[_left] = op[_left];

        op[_right] = op[x];
        tree[_right] = op[_right];

        op[x] = NO_EQ;

        return;
    }

    void assign_to_segment(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] = val;
            tree[x] = val;
            return;
        }

        if (op[x] != NO_EQ)
            propagate(x);
        lli mid = (lx + rx) >> 1;
        assign_to_segment(l, r, val, 2LL * x + 1LL, lx, mid);
        assign_to_segment(l, r, val, 2LL * x + 2LL, mid, rx);
        tree[x] = min(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    lli get_segment_min(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return BIG;
        if (l <= lx and rx <= r)
            return tree[x];
        
        if (op[x] != NO_EQ)
            return op[x];
        
        lli mid = (lx + rx) >> 1;
        return min(
            get_segment_min(l, r, 2LL * x + 1LL, lx, mid),
            get_segment_min(l, r, 2LL * x + 2LL, mid, rx)
        );
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        fill(tree, tree + 2LL * size, 0LL);
        fill(op, op + 2LL * size, NO_EQ);
        return;
    }

    void assign_to_segment(lli l, lli r, lli val) {
        assign_to_segment(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli get_segment_min(lli l, lli r) {
        return get_segment_min(l, r, 0LL, 0LL, size);
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
            st.assign_to_segment(l, r, val);
        } else { // cmd == 2LL
            lli l,
                r;
            cin >> l >> r;
            cout << st.get_segment_min(l, r) << '\n';
        }
    }
    
    return;
}
