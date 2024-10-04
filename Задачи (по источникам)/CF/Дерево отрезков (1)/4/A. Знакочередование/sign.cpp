// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (1LL << 20);



// Дерево отрезков с операцией signed_sum
class segtree {
private:
    lli tree[MAX_SIZE + 5LL];
    lli size;

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size) size <<= 1;
        return;
    }

    void set(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = ((lx & 1LL) ? -val : val);
            return;
        }

        lli mid = (lx + rx) / 2LL;
        if (i < mid)
            set(i, val, 2LL * x + 1LL, lx, mid);
        else
            set(i, val, 2LL * x + 2LL, mid, rx);
        tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
        return;
    }

    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
        return;
    }

    lli signed_sum(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return 0LL;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) / 2LL;
        lli ss1 = signed_sum(l, r, 2LL * x + 1LL, lx, mid),
            ss2 = signed_sum(l, r, 2LL * x + 2LL, mid, rx);
        return (ss1 + ss2);
    }

    lli signed_sum(lli l, lli r) {
        lli res = signed_sum(l, r, 0LL, 0LL, size);
        return ((l & 1LL) ? -res : res);
    }
};



lli N,
    a,
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
    for (int i = 0; i < (int)N; ++i) {
        cin >> a;
        st.set(i, a);
    }

    cin >> M;
    while (M--) {
        lli op;
        cin >> op;

        if (!op) {
            lli i,
                val;
            cin >> i >> val; --i;
            st.set(i, val);
        } else {
            lli l,
                r;
            cin >> l >> r; --l;
            cout << st.signed_sum(l, r) << '\n';
        }
    }
    
    return;
}
