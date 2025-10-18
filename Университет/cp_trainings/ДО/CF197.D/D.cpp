// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define x1 (x << 1) + 1LL
#define x2 (x << 1) + 2LL
#define mx (lx + rx) >> 1

class segtree {
private:
    vector<lli> tree;
    lli size;
    
    lli log2(lli num) {
        lli res = 0LL;
        while (num > 1LL) {
            num >>= 1;
            ++res;
        }
        return res;
    }
    
    void update(lli x, lli lx, lli rx) {
        if (log2(rx - lx) & 1LL)
            tree[x] = tree[x1] | tree[x2];
        else
            tree[x] = tree[x1] ^ tree[x2];
    }
    
    void build(const vector<lli>& data, lli data_size, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < data_size)
                tree[x] = data[lx];
            return;
        }
        
        build(data, data_size, x1, lx, mx);
        build(data, data_size, x2, mx, rx);
        update(x, lx, rx);
    }
    
    void set(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = val;
            return;
        }
        
        if (i < mx)
            set(i, val, x1, lx, mx);
        else
            set(i, val, x2, mx, rx);
        update(x, lx, rx);
    }

public:
    segtree(const vector<lli>& data, lli data_size) {
        size = 1LL;
        while (size < data_size)
            size <<= 1;
        tree.resize((size << 1) - 1LL);
        build(data, data_size, 0LL, 0LL, size);
    }
    
    lli get_root() {
        return tree[0];
    }
    
    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli n,
        m;
    cin >> n >> m;
    n = 1LL << (int)n;
    vector<lli> a(n);
    for (lli& ai : a)
        cin >> ai;
    
    segtree st(a, n);
    while (m--) {
        lli i,
            val;
        cin >> i >> val;
        --i;
        st.set(i, val);
        cout << st.get_root() << '\n';
    }
    
    return 0;
}

