// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define sum                 first
#define wsum                second

#define left                (2LL * x + 1LL)
#define right               (2LL * x + 2LL)

#define res                 first
#define len                 second

const lli MAX_SIZE = (lli)5e5 + 5LL;






class segtree {
private:
    plli tree[MAX_SIZE]; // sum - wsum
    lli op[MAX_SIZE];
    lli size;

    void build(lli *arr, lli sz, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < sz)
                tree[x] = mp(arr[lx], arr[lx]);
            else
                tree[x] = mp(0LL, 0LL);
            return;
        }

        lli mid = (lx + rx) >> 1;
        build(arr, sz, left, lx, mid);
        build(arr, sz, right, mid, rx);
        tree[x] = mp(
            tree[left].sum + tree[right].sum,
            tree[left].wsum + tree[right].wsum + (rx - lx) / 2 * tree[right].sum
        );
        return;
    }

    void add(lli l, lli r, lli d, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            op[x] += d;
            tree[x].sum += d * (rx - lx);
            tree[x].wsum += d * (rx - lx) * (rx - lx + 1LL) / 2LL;
            return;
        }

        lli mid = (lx + rx) >> 1;
        add(l, r, d, left, lx, mid);
        add(l, r, d, right, mid, rx);
        tree[x] = mp(
            tree[left].sum + tree[right].sum + (rx - lx) * op[x],
            tree[left].wsum + tree[right].wsum + (rx - lx) / 2 * tree[right].sum + (rx - lx) * (rx - lx + 1LL) / 2LL * op[x]
        );
        return;
    }

    pair<plli, lli> get_wsum(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return mp(mp(0LL, 0LL), 0LL);
        if (l <= lx and rx <= r)
            return mp(tree[x], rx - lx);
        
        lli mid = (lx + rx) >> 1;
        pair<plli, lli> r1 = get_wsum(l, r, left, lx, mid),
                        r2 = get_wsum(l, r, right, mid, rx);
        return mp(mp(
            r1.res.sum + r2.res.sum + (r1.len + r2.len) * op[x],
            r1.res.wsum + r2.res.wsum + r1.len * r2.res.sum + (r1.len + r2.len) * (r1.len + r2.len + 1LL) / 2LL * op[x]
        ), r1.len + r2.len);
    }

public:
    void init(lli *arr, lli sz) {
        size = 1LL;
        while (size < sz)
            size <<= 1;
        build(arr, sz, 0LL, 0LL, size);
        return;
    }

    void add(lli l, lli r, lli d) {
        add(l, r, d, 0LL, 0LL, size);
        return;
    }

    lli get_wsum(lli l, lli r) {
        return get_wsum(l, r, 0LL, 0LL, size).res.wsum;
    }
};






lli N,
    A[MAX_SIZE];
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
    cin >> N >> Q;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    st.init(A, N);

    while (Q--) {
        cin >> cmd;
        if (cmd == 1LL) {
            lli l,
                r,
                d;
            cin >> l >> r >> d;
            st.add(--l, r, d);
        } else { // cmd == 2LL
            lli l,
                r;
            cin >> l >> r;
            cout << st.get_wsum(--l, r) << '\n';
        }
    }
    
    return;
}
