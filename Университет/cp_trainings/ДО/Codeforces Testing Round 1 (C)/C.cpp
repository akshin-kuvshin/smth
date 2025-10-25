// author: Danila "akshin_" Axyonov

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

#define mx ((lx + rx) / 2LL)
#define x1 (2LL * x + 1LL)
#define x2 (2LL * x + 2LL)

const lli INF = (lli)1e18 + 1LL;

class segtree {
private:
    vector<lli> tree,
                addition;
    lli size;
    
    void build(const vector<lli>& a, lli a_size, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = (lx < a_size ? a[lx] : INF);
            return;
        }
        build(a, a_size, x1, lx, mx);
        build(a, a_size, x2, mx, rx);
        tree[x] = min(
            tree[x1] /* + addition[x1] */ ,
            tree[x2] /* + addition[x2] */
        );
        return;
    }
    
    lli get_min(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return INF;
        if (l <= lx and rx <= r)
            return tree[x] + addition[x];
        return min(
            get_min(l, r, x1, lx, mx),
            get_min(l, r, x2, mx, rx)
        ) + addition[x];
    }
    
    void add(lli l, lli r, lli val, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            addition[x] += val;
            return;
        }
        add(l, r, val, x1, lx, mx);
        add(l, r, val, x2, mx, rx);
        tree[x] = min(
            tree[x1] + addition[x1],
            tree[x2] + addition[x2]
        );
    }

public:
    segtree(const vector<lli>& a, lli a_size) {
        size = 1LL;
        while (size < a_size)
            size *= 2LL;
        tree.resize(2LL * size - 1LL);
        addition.assign(2LL * size - 1LL, 0LL);
        build(a, a_size, 0LL, 0LL, size);
    }
    
    lli get_min(lli l, lli r) {
        return get_min(l, r, 0LL, 0LL, size);
    }
    
    void add(lli l, lli r, lli val) {
        add(l, r, val, 0LL, 0LL, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli& ai : a)
        cin >> ai;
    segtree st(a, n);
    
    lli m;
    cin >> m;
    cin.ignore();
    while (m--) {
        string input;
        stringstream ss;
        
        getline(cin, input);
        ss << input;
        
        lli spaces = 0LL;
        for (char c : input)
            spaces += (lli)(c == ' ');
        if (spaces == 1LL) {
            lli l,
                r;
            ss >> l >> r;
            ++r;
            
            lli res;
            if (l < r)
                res = st.get_min(l, r);
            else // l >= r
                res = min(
                    st.get_min(l, n),
                    st.get_min(0LL, r)
                );
            cout << res << '\n';
        } else { // spaces == 2LL
            lli l,
                r,
                val;
            ss >> l >> r >> val;
            ++r;
            
            if (l < r)
                st.add(l, r, val);
            else { // l >= r
                st.add(l, n, val);
                st.add(0LL, r, val);
            }
        }
    }
    
    return 0;
}

