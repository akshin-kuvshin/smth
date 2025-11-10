// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli BIG_N = 26LL;

class Node;

class Change {
private:
    lli p[BIG_N];

public:
    Change() {
        for (int i = 0; i < (int)BIG_N; ++i)
            p[i] = (lli)i;
    }

    void set(char from, char to) {
        int f = (int)(from - 'a'),
            t = (int)(to - 'a');
        for (int i = 0; i < (int)BIG_N; ++i)
            if (p[i] == f)
                p[i] = t;
    }

    friend class Node;
};

class Node {
private:
    lli cnt[BIG_N];

public:
    Node() {
        fill_n(cnt, BIG_N, 0LL);
    }

    Node(char c) : Node() {
        int i = (int)(c - 'a');
        ++cnt[i];
    }

    lli get(char c) const {
        int i = (int)(c - 'a');
        return cnt[i];
    }

    Node operator+(const Node& nd) const {
        Node res = *this;
        for (int i = 0; i < (int)BIG_N; ++i)
            res.cnt[i] += nd.cnt[i];
        return res;
    }

    Node operator*(const Change& ch) const {
        Node res;
        for (int i = 0; i < (int)BIG_N; ++i)
            res.cnt[ch.p[i]] += cnt[i];
        return res;
    }
};

#define mx ((lx + rx) / 2LL)
#define x1 (2LL * x + 1LL)
#define x2 (2LL * x + 2LL)
class segtree {
private:
    vector<Node> tree;
    vector<Change> change;
    lli size;

    void build(const string& S, lli n, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = ((lx < n) ? Node(S[lx]) : Node());
            return;
        }
        build(S, n, x1, lx, mx);
        build(S, n, x2, mx, rx);
        tree[x] = tree[x1] + tree[x2];
    }

    void set(lli l, lli r, char from, char to, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            change[x].set(from, to);
            return;
        }
        set(l, r, from, to, x1, lx, mx);
        set(l, r, from, to, x2, mx, rx);
        tree[x] = tree[x1] * change[x1] + tree[x2] * change[x2];
    }

    Node count(lli l, lli r, lli x, lli lx, lli rx) const {
        if (rx <= l or r <= lx)
            return Node();
        if (l <= lx and rx <= r)
            return tree[x] * change[x];
        return (count(l, r, x1, lx, mx) + count(l, r, x2, mx, rx)) * change[x];
    }

public:
    segtree(const string& S, lli n) {
        size = 1LL;
        while (size < n)
            size *= 2LL;
        change.assign(2LL * size - 1LL, Change());
        tree.resize(2LL * size - 1LL);
        build(S, n, 0LL, 0LL, size);
    }

    void set(lli l, lli r, char from, char to) {
        set(l, r, from, to, 0LL, 0LL, size);
    }

    lli count(lli l, lli r, char c) const {
        return count(l, r, 0LL, 0LL, size).get(c);
    }
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;
    vector<string> a(n);
    vector<lli> pref(n + 1LL);
    string S;
    for (int i = 0; i < (int)n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + (lli)(a[i].size());
        S += a[i];
    }

    segtree st(S, pref.back());
    while (m--) {
        lli cmd;
        cin >> cmd;
        if (cmd == 1LL) {
            int i;
            char from,
                 to;
            cin >> i >> from >> to;
            --i;
            st.set(pref[i], pref[i + 1], from, to);
        } else { // cmd == 2LL
            lli l,
                r;
            char c;
            cin >> l >> r >> c;
            --l;
            cout << st.count(l, r, c) << '\n';
        }
    }

    return;
}
