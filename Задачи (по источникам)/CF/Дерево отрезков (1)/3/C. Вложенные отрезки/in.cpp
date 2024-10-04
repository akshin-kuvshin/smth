// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e6,
          NO = -1LL;



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

    void set(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = val;
            return;
        }

        lli mid = (lx + rx) / 2LL;
        if (i < mid)
            set(i, val, 2LL * x + 1LL, lx, mid);
        else
            set(i, val, 2LL * x + 2LL, mid, rx);
        tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
        return;
    }

    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
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



lli N_2,
    N,
    A[MAX_SIZE + 5LL];
lli first_ind[MAX_SIZE + 5LL];
segtree st;
lli ans[MAX_SIZE + 5LL];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N_2; N = N_2 * 2LL;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    fill(first_ind, first_ind + N_2 + 1LL, NO);
    st.init(N);

    for (int i = 0; i < (int)N; ++i) {
        if (first_ind[A[i]] == NO)
            first_ind[A[i]] = (lli)i;
        else {
            ans[A[i]] = st.sum(first_ind[A[i]], (lli)i);
            st.set(first_ind[A[i]], 1LL);
        }
    }

    for (int i = 1; i <= (int)N_2; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
    
    return;
}
