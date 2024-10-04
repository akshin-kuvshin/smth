// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (1LL << 20);




class segtree {
private:
    lli tree[MAX_SIZE + 5LL];
    lli size;

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        fill(tree, tree + 2LL * size - 1LL, 0LL);
        return;
    }

    void add(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] += val;
            return;
        }

        lli mid = (lx + rx) / 2LL;
        if (i < mid)
            add(i, val, 2LL * x + 1LL, lx, mid);
        else
            add(i, val, 2LL * x + 2LL, mid, rx);
        tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
        return;
    }

    void add(lli i, lli val) {
        add(i, val, 0LL, 0LL, size);
        return;
    }

    // Сидел 3 часа, потому что не написал ебаный if (r < size)
    void add(lli l, lli r, lli val) {
        add(l, val);
        if (r < size)
            add(r, -val);
        return;
    }

    lli sum(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return 0LL;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) / 2LL;
        return sum(l, r, 2LL * x + 1LL, lx, mid) +
               sum(l, r, 2LL * x + 2LL, mid, rx);
    }

    lli get(lli i) {
        return sum(0LL, i + 1LL, 0LL, 0LL, size);
    }
};




lli N,
    M;
segtree st;

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

    cin >> M;
    while (M--) {
        lli op;
        cin >> op;

        if (op == 1LL) {
            lli l,
                r,
                val;
            cin >> l >> r >> val;
            st.add(l, r, val);
        } else {
            lli i;
            cin >> i;
            cout << st.get(i) << '\n';
        }
    }
    
    return;
}
