// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e6;



class segtree {
private:
    lli tree[MAX_SIZE + 5LL];
    lli size;

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        return;
    }

    void build(lli sz, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < sz)
                tree[x] = 1LL;
            return;
        }

        lli mid = (lx + rx) / 2LL;
        build(sz, 2LL * x + 1LL, lx, mid);
        build(sz, 2LL * x + 2LL, mid, rx);
        tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
        return;
    }

    void build(lli sz) {
        init(sz);
        build(sz, 0LL, 0LL, size);
        return;
    }

    void set(lli i, lli value, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = value;
            return;
        }

        lli mid = (lx + rx) / 2LL;
        if (i < mid)
            set(i, value, 2LL * x + 1LL, lx, mid);
        else
            set(i, value, 2LL * x + 2LL, mid, rx);
        tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
        return;
    }

    void set(lli i, lli value) {
        set(i, value, 0LL, 0LL, size);
        return;
    }

    lli find_kth_from_end(lli k, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL)
            return lx;
        
        lli mid = (lx + rx) / 2LL;
        if (k > tree[2LL * x + 2LL])
            return find_kth_from_end(k - tree[2LL * x + 2LL], 2LL * x + 1LL, lx, mid);
        return find_kth_from_end(k, 2LL * x + 2LL, mid, rx);
    }

    lli find_kth_from_end(lli k) {
        return find_kth_from_end(k, 0LL, 0LL, size);
    }
};



lli N,
    A[MAX_SIZE + 5LL],
    p[MAX_SIZE + 5LL];
segtree st;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    st.build(N);
    for (int i = (int)N - 1; i >= 0; --i) {
        p[i] = st.find_kth_from_end(A[i] + 1LL);
        st.set(p[i], 0LL);
        ++p[i];
    }

    for (int i = 0; i < (int)N; ++i)
        cout << p[i] << ' ';
    cout << '\n';

    return;
}
