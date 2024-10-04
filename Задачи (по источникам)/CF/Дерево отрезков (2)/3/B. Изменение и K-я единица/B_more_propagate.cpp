// author: Danila "akshin_" Aksionov

// Здесь я не накапливаю купулятивные суммы,
// а просто добавляю в функцию ind_of вызов propagate каждый раз,
// когда op[x] == true.
//
// Это решение кажется мне более красивым и элегантным.
//
// Другое решение (B_less_propagate.cpp) пришло мне первым в голову, значит,
// оно более интуитивное, но его чуть сложнее понять - там вызовы propagate
// внутри ind_of заменяются кумулятивными суммами по op[x] для всех посещённых x.

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)4e5 + 5LL;







class segtree {
private:
    lli tree[MAX_SIZE];
    bool op[MAX_SIZE];
    lli size;

    void propagate(lli x, lli lx, lli rx) {
        lli len2 = (rx - lx) >> 1;
        lli _left = 2LL * x + 1LL,
            _right = 2LL * x + 2LL;
        
        // for _left
        op[_left] = !op[_left];
        tree[_left] = len2 - tree[_left];

        // for _right
        op[_right] = !op[_right];
        tree[_right] = len2 - tree[_right];

        // for x
        op[x] = false;

        return;
    }

    void change(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] = !op[x];
            tree[x] = (rx - lx) - tree[x];
            return;
        }

        if (op[x])
            propagate(x, lx, rx);
        
        lli mid = (lx + rx) >> 1;
        change(l, r, 2LL * x + 1LL, lx, mid);
        change(l, r, 2LL * x + 2LL, mid, rx);
        tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
        return;
    }

    // k = 1..N
    lli ind_of(lli k, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL)
            return lx;
        
        if (op[x])
            propagate(x, lx, rx);
        
        lli mid = (lx + rx) >> 1,
            s = tree[2LL * x + 1LL];
        if (k <= s)
            return ind_of(k, 2LL * x + 1LL, lx, mid);
        return ind_of(k - s, 2LL * x + 2LL, mid, rx);
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        fill(tree, tree + 2LL * size, 0LL);
        fill(op, op + 2LL * size, false);
        return;
    }

    void change(lli l, lli r) {
        change(l, r, 0LL, 0LL, size);
        return;
    }

    lli ind_of(lli k) {
        return ind_of(k, 0LL, 0LL, size);
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
                r;
            cin >> l >> r;
            st.change(l, r);
        } else { // cmd == 2LL
            lli k;
            cin >> k;
            cout << st.ind_of(++k) << '\n';
        }
    }
    
    return;
}
