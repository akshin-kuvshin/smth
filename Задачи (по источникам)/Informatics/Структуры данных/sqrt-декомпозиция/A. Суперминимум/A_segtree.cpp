// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define left                (2LL * x + 1LL)
#define right               (2LL * x + 2LL)

const lli MAX_SIZE = (lli)1.5e5 + 5LL,
          INF = (lli)1e18 + 1LL;



class segtree {
private:
    vector<lli> tree;
    lli size;

    void build(lli *arr, lli sz, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = (lx < sz ? arr[lx] : INF);
            return;
        }

        lli mid = (lx + rx) >> 1;
        build(arr, sz, left, lx, mid);
        build(arr, sz, right, mid, rx);
        tree[x] = min(tree[left], tree[right]);
        return;
    }

    lli get_min(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return INF;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        return min(
            get_min(l, r, left, lx, mid),
            get_min(l, r, right, mid, rx)
        );
    }

public:
    void init(lli *arr, lli sz) {
        size = 1LL;
        while (size < sz)
            size <<= 1;
        tree.resize(2LL * size - 1LL);
        build(arr, sz, 0LL, 0LL, size);
        return;
    }

    lli get_min(lli l, lli r) { return get_min(l, r, 0LL, 0LL, size); }
};



lli N,
    A[MAX_SIZE],
    K;
segtree st;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    st.init(A, N);

    for (int i = 0; i + (int)K <= (int)N; ++i)
        cout << st.get_min((lli)i, (lli)i + K) << ' ';
    cout << '\n';
    
    return;
}
