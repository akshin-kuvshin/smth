// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm> // std::fill
#define NO_EQ -1LL
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

    Node(lli __sum, lli __length) {
        sum = __sum;
        length = __length;
        return;
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

    void propagate(lli x, lli length) {
        lli _left = 2LL * x + 1LL,
            _right = 2LL * x + 2LL,
            length2 = length >> 1;
        
        op[_left] = op[x];
        tree[_left] = op[_left] * length2;
        
        op[_right] = op[x];
        tree[_right] = op[_right] * length2;

        op[x] = NO_EQ;

        return;
    }

    void assign_to_segment(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] = val;
            tree[x] = op[x] * (rx - lx);
            return;
        }

        if (op[x] != NO_EQ)
            propagate(x, rx - lx);
        lli mid = (lx + rx) >> 1;
        assign_to_segment(l, r, val, 2LL * x + 1LL, lx, mid);
        assign_to_segment(l, r, val, 2LL * x + 2LL, mid, rx);
        tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
        return;
    }

    Node get_segment_sum(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return Node();
        if (l <= lx and rx <= r)
            return Node(tree[x], rx - lx);
        
        if (op[x] != NO_EQ) {
            lli __l = max(l, lx),
                __r = min(r, rx);
            lli length = __r - __l;
            return Node(op[x] * length, length);
        }

        lli mid = (lx + rx) >> 1;
        return combine(
            get_segment_sum(l, r, 2LL * x + 1LL, lx, mid),
            get_segment_sum(l, r, 2LL * x + 2LL, mid, rx)
        );
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        fill(tree, tree + 2LL * size, 0LL);
        fill(op, op + 2LL * size, NO_EQ);
        return;
    }

    void assign_to_segment(lli l, lli r, lli val) {
        assign_to_segment(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli get_segment_sum(lli l, lli r) {
        return get_segment_sum(l, r, 0LL, 0LL, size).sum;
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
            st.assign_to_segment(l, r, val);
        } else { // cmd == 2LL
            lli l,
                r;
            cin >> l >> r;
            cout << st.get_segment_sum(l, r) << '\n';
        }
    }
    
    return;
}
