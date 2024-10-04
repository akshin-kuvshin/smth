// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm> // for std::fill
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define BAD                 -1LL

const lli MAX_SIZE = (lli)4e5 + 5LL;







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

        lli _left = 2LL * x + 1LL,
            _right = 2LL * x + 2LL;

        lli mid = (lx + rx) >> 1;
        add(l, r, val, _left, lx, mid);
        add(l, r, val, _right, mid, rx);
        tree[x] = max(tree[_left], tree[_right]) + op[x];
        return;
    }

    lli first(lli val, lli l, lli x, lli lx, lli rx) {
        if (rx <= l)
            return BAD;
        if (tree[x] < val)
            return BAD;
        if (rx - lx == 1LL)
            return lx;
        
        lli _left = 2LL * x + 1LL,
            _right = 2LL * x + 2LL;
        
        lli mid = (lx + rx) >> 1,
            res;
        if ((res = first(val - op[x], l, _left, lx, mid)) != BAD)
            return res;
        res = first(val - op[x], l, _right, mid, rx);
        return res;
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

    lli first(lli val, lli l) {
        return first(val, l, 0LL, 0LL, size);
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
            lli val,
                l;
            cin >> val >> l;
            cout << st.first(val, l) << '\n';
        }
    }
    
    return;
}
