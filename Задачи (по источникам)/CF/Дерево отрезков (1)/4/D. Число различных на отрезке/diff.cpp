// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)4e5,
          MIN_ELEM = 1LL,
          MAX_ELEM = 40LL;



class Node {
public:
    bool used[MAX_ELEM + 1LL];

    Node() {
        fill(used + MIN_ELEM, used + MAX_ELEM + 1LL, false);
        return;
    }

    Node (lli ind) : Node() {
        used[ind] = true;
        return;
    }

    lli count() {
        lli cnt = 0LL;
        for (int i = (lli)MIN_ELEM; i <= (lli)MAX_ELEM; ++i)
            cnt += used[i];
        return cnt;
    }
};

Node combine(const Node &n1, const Node &n2) {
    Node comb = Node();
    for (int i = (int)MIN_ELEM; i <= (int)MAX_ELEM; ++i)
        comb.used[i] = (n1.used[i] or n2.used[i]);
    return comb;
}



class segtree {
private:
    Node tree[MAX_SIZE + 5LL];
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
                tree[x] = Node(arr[lx]);
            else
                tree[x] = Node();
            return;
        }

        lli mid = (lx + rx) >> 1;
        build(arr, sz, 2LL * x + 1LL, lx, mid);
        build(arr, sz, 2LL * x + 2LL, mid, rx);
        tree[x] = combine(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    void build(lli *arr, lli sz) {
        init(sz);
        build(arr, sz, 0LL, 0LL, size);
        return;
    }

    Node count_diffs(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return Node();
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        return combine(count_diffs(l, r, 2LL * x + 1LL, lx, mid),
                       count_diffs(l, r, 2LL * x + 2LL, mid, rx));
    }

    lli count_diffs(lli l, lli r) {
        return count_diffs(l, r, 0LL, 0LL, size).count();
    }

    void set(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = Node(val);
            return;
        }

        lli mid = (lx + rx) >> 1;
        if (i < mid)
            set(i, val, 2LL * x + 1LL, lx, mid);
        else
            set(i, val, 2LL * x + 2LL, mid, rx);
        tree[x] = combine(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
        return;
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
        lli cmd;
        cin >> cmd;

        if (cmd == 1LL) {
            lli l,
                r;
            cin >> l >> r; --l;
            cout << st.count_diffs(l, r) << '\n';
        } else {
            lli i,
                val;
            cin >> i >> val; --i;
            st.set(i, val);
        }
    }
    
    return;
}
