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

    lli sum(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return 0LL;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) / 2LL;
        return sum(l, r, 2LL * x + 1LL, lx, mid) +
               sum(l, r, 2LL * x + 2LL, mid, rx);
    }

    lli sum(lli l, lli r) {
        return sum(l, r, 0LL, 0LL, size);
    }
};



lli N,
    A[MAX_SIZE + 5LL];
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
    
    st.init(N);
    for (int i = 0; i < (int)N; ++i) {
        cout << st.sum(A[i] - 1LL, N) << ' ';
        st.set(A[i] - 1LL, 1LL);
    }

    cout << '\n';    
    return;
}
