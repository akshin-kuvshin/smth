// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e5,
          MOD = (lli)1e9 + 7LL;



class segtree {
private:
    lli tree[MAX_SIZE];
    lli op[MAX_SIZE];
    lli size;

    void build(lli N, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < N)
                tree[x] = 1LL;
            else
                tree[x] = 0LL;
            return;
        }

        lli mid = (lx + rx) >> 1;
        build(N, 2LL * x + 1LL, lx, mid);
        build(N, 2LL * x + 2LL, mid, rx);
        tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
        return;
    }

    void prod_each(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] = (op[x] * val) % MOD;
            tree[x] = (tree[x] * val) % MOD;
            return;
        }

        lli mid = (lx + rx) >> 1;
        prod_each(l, r, val, 2LL * x + 1LL, lx, mid);
        prod_each(l, r, val, 2LL * x + 2LL, mid, rx);
        tree[x] = (((tree[2LL * x + 1LL] + tree[2LL * x + 2LL]) % MOD) * op[x]) % MOD;
        return;
    }

    lli sum(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return 0LL;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        lli sum_l = sum(l, r, 2LL * x + 1LL, lx, mid),
            sum_r = sum(l, r, 2LL * x + 2LL, mid, rx);
        return (((sum_l + sum_r) % MOD) * op[x]) % MOD;
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        build(original_size, 0LL, 0LL, size); // for tree[]
        fill(op, op + 2LL * size, 1LL); // for op[]
        return;
    }

    void prod_each(lli l, lli r, lli val) {
        prod_each(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli sum(lli l, lli r) {
        return sum(l, r, 0LL, 0LL, size);
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
            st.prod_each(l, r, val);
        } else { // cmd == 2LL
            lli l,
                r;
            cin >> l >> r;
            cout << st.sum(l, r) << '\n';
        }
    }
    
    return;
}
