// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define left                (2LL * x + 1LL)
#define right               (2LL * x + 2LL)

const lli MAX_SIZE = (lli)2e5 + 5LL,
          INF = (lli)1e18 + 1LL;




class segtree {
private:
    vector<lli> tree;
    vector<lli> op;
    lli size;

    lli get_min(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return INF;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        return min(
            get_min(l, r, left, lx, mid),
            get_min(l, r, right, mid, rx)
        ) + op[x];
    }

    void add(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] += val;
            tree[x] += val;
            return;
        }

        lli mid = (lx + rx) >> 1;
        add(l, r, val, left, lx, mid);
        add(l, r, val, right, mid, rx);
        tree[x] = min(tree[left], tree[right]) + op[x];
        return;
    }

public:
    void init(lli original_size, lli K) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        
        tree.assign(2LL * size - 1LL, K);
        op.assign(2LL * size - 1LL, 0LL);
        
        return;
    }

    lli get_min(lli l, lli r) { return get_min(l, r, 0LL, 0LL, size); }

    void add(lli l, lli r, lli val) { add(l, r, val, 0LL, 0LL, size); return; }
};




lli N,
    K;
segtree st;
lli Q,
    l,
    r;
lli m;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    st.init(N, K);

    cin >> Q;
    while (Q--) {
        cin >> l >> r;
        m = st.get_min(l, r);
        
        if (m == 0LL)
            cout << "0\n";
        else {
            st.add(l, r, -1LL);
            cout << "1\n";
        }
    }
    
    return;
}
