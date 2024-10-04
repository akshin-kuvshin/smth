// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

// Странность с константой. В теории должно работать и с 2e5 (ограничения на размер массива 1e5,
// значит в дереве будет не больше 2e5 узлов), но выдаёт выход за границы массива (???!!!),
// так что добавим ещё 100к - нам не сложно, а тестилке приятно)
const lli MAX_SIZE = (lli)3e5,
          LIL_NUM = 1LL,
          BIG_NUM = 40LL;
          
class Node {
public:
    lli cnt[BIG_NUM + 5LL];
    lli inv_amount;

    Node() {
        fill(cnt + LIL_NUM, cnt + BIG_NUM + 1LL, 0LL);
        inv_amount = 0LL;
        return;
    }
    
    Node(lli num) : Node() {
        cnt[num] = 1LL;
        return;
    }
};

Node combine(const Node &n1, const Node &n2) {
    Node result = Node();

    // Считаем result.cnt
    for (int i = (int)LIL_NUM; i <= (int)BIG_NUM; ++i)
        result.cnt[i] = n1.cnt[i] + n2.cnt[i];
    
    // Считаем result.inv_amount
    result.inv_amount = n1.inv_amount + n2.inv_amount;
    
    lli amount_of_biggers = 0LL;
    for (int i = (int)LIL_NUM; i <= (int)BIG_NUM; ++i)
        amount_of_biggers += n1.cnt[i];
    for (int i = (int)LIL_NUM; i <= (int)BIG_NUM; ++i) {
        amount_of_biggers -= n1.cnt[i];
        result.inv_amount += amount_of_biggers * n2.cnt[i];
    }

    return result;
}

class segtree {
private:
    Node tree[MAX_SIZE + 5LL];
    lli size;

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        return;
    }

    void build(lli *arr, lli sz, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < sz)
                tree[x] = Node(arr[lx]);
            else
                tree[x] = Node();
            return;
        }

        lli mid = (lx + rx) >> 1;
        build(arr, sz, 2LL * x + 1LL, lx, mid);
        build(arr, sz, 2LL * x + 2LL, mid, rx);
        tree[x] = combine(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    void build(lli *arr, lli sz) {
        init(sz);
        build(arr, sz, 0LL, 0LL, size);
        return;
    }

    Node inv_on_seg(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return Node();
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) >> 1;
        Node res1 = inv_on_seg(l, r, 2LL * x + 1LL, lx, mid),
             res2 = inv_on_seg(l, r, 2LL * x + 2LL, mid, rx);
        return combine(res1, res2);
    }

    lli inv_on_seg(lli l, lli r) {
        Node result = inv_on_seg(l, r, 0LL, 0LL, size);
        return result.inv_amount;
    }

    void set(lli i, lli val, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            tree[x] = Node(val);
            return;
        }

        lli mid = (lx + rx) >> 1;
        if (i < mid)
            set(i, val, 2LL * x + 1LL, lx, mid);
        else
            set(i, val, 2LL * x + 2LL, mid, rx);
        tree[x] = combine(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        return;
    }

    void set(lli i, lli val) {
        set(i, val, 0LL, 0LL, size);
        return;
    }
};

lli N,
    A[MAX_SIZE + 5LL];
lli Q;
segtree st;

void solve() {
    cin >> N >> Q;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    st.build(A, N);
    
    while (Q--) {
        lli op;
        cin >> op;

        if (op == 1LL) {
            lli _l,
                _r;
            cin >> _l >> _r;
            --_l;
            cout << st.inv_on_seg(_l, _r) << '\n';
        } else {
            lli _i,
                _val;
            cin >> _i >> _val;
            --_i;
            st.set(_i, _val);
        }
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
