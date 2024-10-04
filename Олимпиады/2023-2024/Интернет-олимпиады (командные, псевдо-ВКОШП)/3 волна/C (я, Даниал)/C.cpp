// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e6;





// set + sum
class segtree {
private:
    lli tree[MAX_SIZE];
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





lli N,
    tmp,
    ind[MAX_SIZE];
lli stick,
    to_release;
segtree st;
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> tmp;
        --tmp;
        ind[tmp] = (lli)i;
    }

    stick = N;
    st.init(N);
    while (to_release < N) {
        lli i = ind[to_release++];
        st.set(i, 1LL);
        i -= st.sum(0LL, i);

        if (i < stick) {
            // Ставим stick на место
            ans += stick - (i + 1LL);
            stick = i + 1LL;

            // Удаляем
            ++ans;
            --stick;
        } else { // stick <= i
            // Ставим stick на место
            ans += i - stick;
            stick = i;

            // Удаляем
            ++ans;
        }
    }
    
    cout << ans << '\n';
    return;
}
