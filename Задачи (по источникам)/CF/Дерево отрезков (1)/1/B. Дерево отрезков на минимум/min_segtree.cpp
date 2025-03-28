// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

const lli MAX_SIZE = (1LL << 20),
          BIG = (lli)1e10;

// Дерево отрезков на минимум
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
        tree[x] = min(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
        return;
    }

    lli segmin(lli l, lli r, lli x, lli lx, lli rx) {
        // Если полностью снаружи
        if (rx <= l or r <= lx)
            return BIG;
        // Если полностью внутри
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) / 2LL;
        lli min1 = segmin(l, r, 2LL * x + 1LL, lx, mid);
        lli min2 = segmin(l, r, 2LL * x + 2LL, mid, rx);
        return min(min1, min2);
    }

    lli segmin(lli l, lli r) {
        return segmin(l, r, 0LL, 0LL, size);
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
    cin >> N >> M;
    st.init(N);
    for (int i = 0; i < (int)N; ++i) {
        lli tmp;
        cin >> tmp;
        st.set(i, tmp);
    }
    
    while (M--) {
        lli op;
        cin >> op;

        if (op == 1LL) {
            lli i,
                val;
            cin >> i >> val;
            st.set(i, val);
        } else {
            lli l,
                r;
            cin >> l >> r;
            cout << st.segmin(l, r) << '\n';
        }
    }
    
    return;
}
