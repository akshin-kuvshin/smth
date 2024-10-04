// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

#define value first
#define amount second

const lli MAX_SIZE = (1LL << 20),
          BIG = (lli)1e10;

class segtree {
private:
    pair<lli, lli> tree[MAX_SIZE + 5LL];
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
            tree[x] = mp(val, 1LL);
            return;
        }

        lli mid = (lx + rx) / 2LL;
        if (i < mid)
            set(i, val, 2LL * x + 1LL, lx, mid);
        else
            set(i, val, 2LL * x + 2LL, mid, rx);
        
        auto son1 = tree[2LL * x + 1LL],
             son2 = tree[2LL * x + 2LL];
        
        if (son1.value < son2.value)
            tree[x] = son1;
        else if (son1.value == son2.value)
            tree[x] = mp(son1.value, son1.amount + son2.amount);
        else
            tree[x] = son2;

        return;
    }

    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
        return;
    }

    pair<lli, lli> segmin(lli l, lli r, lli x, lli lx, lli rx) {
        // Если полностью снаружи
        if (rx <= l or r <= lx)
            return mp(BIG, 0LL);
        // Если полностью внутри
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) / 2LL;
        auto min1 = segmin(l, r, 2LL * x + 1LL, lx, mid),
             min2 = segmin(l, r, 2LL * x + 2LL, mid, rx);
        
        if (min1.value < min2.value)
            return min1;
        else if (min1.value == min2.value)
            return mp(min1.value, min1.amount + min2.amount);
        return min2;
    }

    pair<lli, lli> segmin(lli l, lli r) {
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
            
            auto result = st.segmin(l, r);
            cout << result.value << ' ' << result.amount << '\n';
        }
    }
    
    return;
}
