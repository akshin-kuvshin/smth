// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (1LL << 20),
          BAD = -1LL;



// Дерево с операцией max
class segtree {
private:
    lli tree[MAX_SIZE + 5LL];
    lli size;

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        return;
    }

    void build(lli *arr, lli sz, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < sz)
                tree[x] = arr[lx];
            return;
        }

        lli mid = (lx + rx) / 2LL;
        build(arr, sz, 2LL * x + 1LL, lx, mid);
        build(arr, sz, 2LL * x + 2LL, mid, rx);
        tree[x] = max(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    void build(lli *arr, lli sz) {
        init(sz);
        build(arr, sz, 0LL, 0LL, size);
        return;
    }

    void set(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = val;
            return;
        }

        lli mid = (lx + rx) / 2LL;
        if (i < mid)
            set(i, val, 2LL * x + 1LL, lx, mid);
        else
            set(i, val, 2LL * x + 2LL, mid, rx);
        tree[x] = max(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
        return;
    }

    lli first_above(lli val, lli x, lli lx, lli rx) {
        if (tree[x] < val)
            return BAD;
        if (rx - lx == 1LL)
            return lx;
        
        lli mid = (lx + rx) / 2LL,
            res;
        if ((res = first_above(val, 2LL * x + 1LL, lx, mid)) != BAD)
            return res;
        res = first_above(val, 2LL * x + 2LL, mid, rx);
        return res;
    }

    lli first_above(lli val) {
        return first_above(val, 0LL, 0LL, size);
    }
};



lli N,
    A[MAX_SIZE + 5LL],
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
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    st.build(A, N);

    while (M--) {
        lli op;
        cin >> op;

        if (op == 1LL) {
            lli i,
                val;
            cin >> i >> val;
            st.set(i, val);
        } else {
            lli val;
            cin >> val;
            cout << st.first_above(val) << '\n';
        }
    }
    
    return;
}
