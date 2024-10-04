// author: Danila "akshin_" Axyonov
// FINAL VERSION
// P.S.: я всё перепутал... Левые взлёты в моём коде - это на самом деле правые взлёты из условия, ну и наоборот тоже... :(

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)5e5;





class segtree {
private:
    class Node {
    public:
        lli lt;
        lli rt;
        lli l;
        lli r;

        Node() {
            lt = 0LL;
            rt = 0LL;
            l = -1LL;
            r = -1LL;
            return;
        }

        Node(lli __l, lli __r) : Node() {
            l = __l;
            r = __r;
            return;
        }

        Node(lli __lt, lli __rt, lli __l, lli __r) {
            lt = __lt;
            rt = __rt;
            l = __l;
            r = __r;
            return;
        }
    };

    Node tree[MAX_SIZE];
    lli size;
    lli arr[MAX_SIZE];

    Node combine(const Node &n1, const Node &n2) {
        Node result = Node(
            n1.lt + n2.lt,
            n1.rt + n2.rt,
            n1.l,
            n2.r
        );

        if ((arr[n1.r - 2LL] == 1LL and arr[n1.r - 1LL] == 2LL and arr[n2.l] == 3LL) or
            (arr[n1.r - 1LL] == 1LL and arr[n2.l] == 2LL and arr[n2.l + 1LL] == 3LL))
            ++result.lt;
        else if ((arr[n1.r - 2LL] == 3LL and arr[n1.r - 1LL] == 2LL and arr[n2.l] == 1LL) or
                 (arr[n1.r - 1LL] == 3LL and arr[n2.l] == 2LL and arr[n2.l + 1LL] == 1LL))
            ++result.rt;
        
        return result;
    }

    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        return;
    }

    void build(lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = Node(lx, rx);
            return;
        }

        lli mid = (lx + rx) >> 1;
        build(2LL * x + 1LL, lx, mid);
        build(2LL * x + 2LL, mid, rx);
        if (rx - lx < 4LL) // rx - lx == 2LL
            tree[x] = Node(lx, rx);
        else // rx - lx >= 4LL
            tree[x] = combine(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    void set(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            arr[i] = val;
            return;
        }

        lli mid = (lx + rx) >> 1;
        if (i < mid)
            set(i, val, 2LL * x + 1LL, lx, mid);
        else // i >= mid
            set(i, val, 2LL * x + 2LL, mid, rx);
        
        if (rx - lx >= 4LL)
            tree[x] = combine(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    void get_nodes(vector<Node> &ns, lli l, lli r) {
        get_nodes(ns, l, r, 0LL, 0LL, size);
        return;
    }
    
    void get_nodes(vector<Node> &ns, lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return;
        if (l <= lx and rx <= r) {
            ns.pb(tree[x]);
            return;
        }

        lli mid = (lx + rx) >> 1;
        get_nodes(ns, l, r, 2LL * x + 1LL, lx, mid);
        get_nodes(ns, l, r, 2LL * x + 2LL, mid, rx);
        return;
    }

public:
    void build(lli *_arr, lli _sz) {
        copy(_arr, _arr + _sz, arr);
        init(_sz);
        build(0LL, 0LL, size);
        return;
    }

    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
        return;
    }

    plli count(lli l, lli r) {
        vector<Node> ns;
        get_nodes(ns, l, r);
        
        lli general_lt = 0LL,
            general_rt = 0LL;
        for (Node n : ns) {
            general_lt += n.lt;
            general_rt += n.rt;
        }
        
        int _sz = (int)ns.size();
        for (int i = 0; i + 1 < _sz; ++i) {
            Node n1 = ns[i],
                 n2 = ns[i + 1];
            if (n1.r - n1.l >= 2LL and arr[n1.r - 2LL] == 1LL and arr[n1.r - 1LL] == 2LL and arr[n2.l] == 3LL) {
                ++general_lt;
            } else if (n2.r - n2.l >= 2LL and arr[n1.r - 1LL] == 1LL and arr[n2.l] == 2LL and arr[n2.l + 1LL] == 3LL) {
                ++general_lt;
            } else if (n1.r - n1.l >= 2LL and arr[n1.r - 2LL] == 3LL and arr[n1.r - 1LL] == 2LL and arr[n2.l] == 1LL) {
                ++general_rt;
            } else if (n2.r - n2.l >= 2LL and arr[n1.r - 1LL] == 3LL and arr[n2.l] == 2LL and arr[n2.l + 1LL] == 1LL) {
                ++general_rt;
            }
        }

        return mp(general_lt, general_rt);
    }
};





lli N,
    A[MAX_SIZE];
segtree st;
lli Q;
char cmd;

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
    st.build(A, N);
    
    cin >> Q;
    while (Q--) {
        cin >> cmd;
        if (cmd == '?') {
            lli l,
                r,
                t;
            cin >> l >> r >> t;
            --l;
            plli res = st.count(l, r);
            cout << (t == 1LL ? res.first : (res.first + res.second)) << '\n';
        } else { // cmd == '!'
            lli i,
                val;
            cin >> i >> val;
            --i;
            st.set(i, val);
        }
    }
    
    return;
}

/* test input:

10
3 1 1 3 2 1 1 1 3 1
10
? 7 10 1
? 2 4 1
? 4 9 2
? 8 10 2
? 3 7 2
! 3 1
! 2 1
! 2 2
! 10 2
? 8 9 1

*/

/* test output:

0
0
1
0
1
0

*/
