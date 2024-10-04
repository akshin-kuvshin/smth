// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e5;



class Node {
public:
    lli sum;
    lli length;

    Node() {
        sum = 0LL;
        length = 0LL;
        return;
    }

    Node(lli _sum, lli _length) {
        sum = _sum;
        length = _length;
        return;
    }

    Node add_to_each(lli val) {
        sum += val * length;
        return *this;
    }
};

Node combine(const Node &n1, const Node &n2) {
    return Node(
        n1.sum + n2.sum,
        n1.length + n2.length
    );
}



class segtree {
private:
    lli tree[MAX_SIZE];
    lli op[MAX_SIZE];
    lli size;

    void add_to_each(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] += val;
            tree[x] += val * (rx - lx);
            return;
        }

        lli mid = (lx + rx) >> 1;
        add_to_each(l, r, val, 2LL * x + 1LL, lx, mid);
        add_to_each(l, r, val, 2LL * x + 2LL, mid, rx);
        tree[x] = (tree[2LL * x + 1LL] + tree[2LL * x + 2LL]) + op[x] * (rx - lx);
        return;
    }

    Node sum(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return Node();
        if (l <= lx and rx <= r)
            return Node(tree[x], rx - lx);
        
        lli mid = (lx + rx) >> 1;
        Node res_l = sum(l, r, 2LL * x + 1LL, lx, mid),
             res_r = sum(l, r, 2LL * x + 2LL, mid, rx);
        return combine(res_l, res_r).add_to_each(op[x]);
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

    void add_to_each(lli l, lli r, lli val) {
        add_to_each(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli sum(lli l, lli r) {
        return sum(l, r, 0LL, 0LL, size).sum;
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
            st.add_to_each(l, r, val);
        } else { // cmd == 2LL
            lli l,
                r;
            cin >> l >> r;
            cout << st.sum(l, r) << '\n';
        }
    }
    
    return;
}
