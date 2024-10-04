// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
#define NO_EQ (lli)1e10
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e5;



class Node {
public:
    lli sum;
    lli pref;
    lli suf;
    lli max;

    Node() {
        sum = 0LL;
        pref = 0LL;
        suf = 0LL;
        max = 0LL;
        return;
    }

    Node(lli _sum, lli _pref, lli _suf, lli _max) {
        sum = _sum;
        pref = _pref;
        suf = _suf;
        max = _max;
        return;
    }

    Node(lli val, lli sz) : Node() {
        sum = val * sz;
        
        if (val <= 0LL)
            return;
        
        pref = val * sz;
        suf = val * sz;
        max = val * sz;
        return;
    }
};

Node combine(const Node &n1, const Node &n2) {
    return Node(
        n1.sum + n2.sum,
        max(n1.pref, n1.sum + n2.pref),
        max(n1.suf + n2.sum, n2.suf),
        max(max(n1.max, n2.max), n1.suf + n2.pref)
    );
}



class segtree {
private:
    Node tree[MAX_SIZE];
    lli op[MAX_SIZE];
    lli size;

    void propagate(lli x, lli length) {
        lli _left = 2LL * x + 1LL,
            _right = 2LL * x + 2LL,
            sublength = (length >> 1);
        
        op[_left] = op[x];
        tree[_left] = Node(op[_left], sublength);

        op[_right] = op[x];
        tree[_right] = Node(op[_right], sublength);

        op[x] = NO_EQ;

        return;
    }

    void assign_to_segment(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] = val;
            tree[x] = Node(op[x], rx - lx);
            return;
        }

        if (op[x] != NO_EQ)
            propagate(x, rx - lx);
        
        lli mid = (lx + rx) >> 1;
        assign_to_segment(l, r, val, 2LL * x + 1LL, lx, mid);
        assign_to_segment(l, r, val, 2LL * x + 2LL, mid, rx);
        tree[x] = combine(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        fill(tree, tree + 2LL * size, Node());
        fill(op, op + 2LL * size, NO_EQ);
        return;
    }

    void assign_to_segment(lli l, lli r, lli val) {
        assign_to_segment(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli get_max_segment_sum() {
        return tree[0].max;
    }
};



lli N;
segtree st;
lli Q,
    _l,
    _r,
    _val;

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
        cin >> _l >> _r >> _val;
        st.assign_to_segment(_l, _r, _val);
        cout << st.get_max_segment_sum() << '\n';
    }
    
    return;
}
