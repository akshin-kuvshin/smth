// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e6 + 5LL;




// set + sum
class segtree {
private:
    lli tree[4LL * MAX_SIZE];
    lli size;

    void set(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = val;
            return;
        }

        lli mid = (lx + rx) >> 1;
        if (i < mid)
            set(i, val, 2LL * x + 1LL, lx, mid);
        else
            set(i, val, 2LL * x + 2LL, mid, rx);
        tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
        return;
    }

    lli sum(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return 0LL;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        return sum(l, r, 2LL * x + 1LL, lx, mid) +
               sum(l, r, 2LL * x + 2LL, mid, rx);
    }

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        fill(tree, tree + 2LL * size, 0LL);
        return;
    }

    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
        return;
    }

    lli sum(lli l, lli r) {
        return sum(l, r, 0LL, 0LL, size);
    }
};




lli N;
lli A[MAX_SIZE];
segtree st;
lli inv;
lli _min,
    t;
deque<lli> dq;

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
        inv += st.sum(A[i] + 1LL, N + 1LL);
        st.set(A[i], 1LL);
    }

    for (int i = 0; i < (int)N; ++i)
        dq.push_back(A[i]);


    _min = inv;
    t = 0LL;
    for (int _ = 1; _ + 1 <= (int)N; ++_) {
        lli elem = dq.front();
        dq.pop_front();
        dq.push_back(elem);

        inv -= elem - 1LL;
        inv += N - elem;

        if (inv < _min) {
            _min = inv;
            t = (lli)_;
        }
    }

    cout << t << '\n';
    return;
}
