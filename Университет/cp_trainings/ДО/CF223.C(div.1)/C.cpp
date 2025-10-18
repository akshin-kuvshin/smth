// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

#define x1 2LL * x + 1LL
#define x2 2LL * x + 2LL
#define mx (lx + rx) / 2LL

struct Node {
    lli a;
    lli b;
    lli c;
};

Node merge(Node n1, Node n2) {
    lli d = min(n1.b, n2.c);
    return {
        n1.a + n2.a + 2LL * d,
        n1.b + n2.b - d,
        n1.c + n2.c - d
    };
}

class segtree {
private:
    vector<Node> tree;
    lli size;
    
    void build(const string& S, lli S_len, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < S_len) {
                if (S[lx] == '(')
                    tree[x] = {0LL, 1LL, 0LL};
                else // S[lx] == ')'
                    tree[x] = {0LL, 0LL, 1LL};
            } else // lx >= S_len
                tree[x] = {0LL, 0LL, 0LL};
            return;   
        }
        
        build(S, S_len, x1, lx, mx);
        build(S, S_len, x2, mx, rx);
        tree[x] = merge(tree[x1], tree[x2]);
    }
    
    Node count(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return {0LL, 0LL, 0LL};
        if (l <= lx and rx <= r)
            return tree[x];
        return merge(
            count(l, r, x1, lx, mx),
            count(l, r, x2, mx, rx)
        );
    }

public:
    segtree(const string& S, lli S_len) {
        size = 1LL;
        while (size < S_len)
            size *= 2LL;
        tree.resize(2LL * size - 1LL);
        build(S, S_len, 0LL, 0LL, size);
    }
    
    lli count(lli l, lli r) {
        return count(l, r, 0LL, 0LL, size).a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S;
    cin >> S;
    lli S_len = (lli)S.size();
    segtree st(S, S_len);
    
    lli m;
    cin >> m;
    while (m--) {
        lli l,
            r;
        cin >> l >> r;
        --l;
        cout << st.count(l, r) << '\n';
    }
    
    return 0;
}

