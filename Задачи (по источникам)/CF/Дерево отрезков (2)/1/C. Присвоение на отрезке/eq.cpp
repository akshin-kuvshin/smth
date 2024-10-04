// author: Danila "akshin_" Aksionov

#include <iostream>
#define NO_EQ -1LL
#define START_EQ 0LL
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e5;

class segtree {
private:
    lli tree[MAX_SIZE];
    lli size;

    void modify(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            tree[x] = val;
            return;
        }

        if (tree[x] != NO_EQ) {
            // Проталкиваем
            tree[2LL * x + 1LL] = tree[x];
            tree[2LL * x + 2LL] = tree[x];
            tree[x] = NO_EQ;
        }

        lli mid = (lx + rx) >> 1;
        modify(l, r, val, 2LL * x + 1LL, lx, mid);
        modify(l, r, val, 2LL * x + 2LL, mid, rx);
        return;
    }

    lli get(lli i, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL)
            return tree[x];
        
        if (tree[x] != NO_EQ)
            return tree[x];
        lli mid = (lx + rx) >> 1;
        if (i < mid)
            return get(i, 2LL * x + 1LL, lx, mid);
        return get(i, 2LL * x + 2LL, mid, rx);
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        fill(tree, tree + 2LL * size, NO_EQ);
        return;
    }

    void modify(lli l, lli r, lli val) {
        modify(l, r, val, 0LL, 0LL, size);
        return;
    }

    lli get(lli i) {
        lli result = get(i, 0LL, 0LL, size);
        return ((result == NO_EQ) ? START_EQ : result);
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
            st.modify(l, r, val);
        } else { // cmd == 2LL
            lli i;
            cin >> i;
            cout << st.get(i) << '\n';
        }
    }
    
    return;
}
