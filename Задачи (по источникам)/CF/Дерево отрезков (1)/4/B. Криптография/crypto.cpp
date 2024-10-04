// author: Danila "akshin_" Aksionov
// пысы: ненавижу писать код с телефона :(
// бу-бу-бу, я ебу козу...

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (1LL << 20);




class matrix2x2 {
public:
    lli a11;
    lli a12;
    lli a21;
    lli a22;

    void mod_eq(lli mod) {
        a11 %= mod;
        a12 %= mod;
        a21 %= mod;
        a22 %= mod;
        return;
    }

    void input() {
        cin >> a11 >> a12 >> a21 >> a22;
        return;
    }

    void print() {
        cout << a11 << ' ' << a12 << '\n'
             << a21 << ' ' << a22 << '\n';
        cout << '\n';
    }
};

// Единичная матрица - нейтральный элемент по операции умножения матриц
const matrix2x2 E = { 1LL, 0LL,
                      0LL, 1LL };

matrix2x2 prod(const matrix2x2 &m1, const matrix2x2 &m2) {
    return {
        m1.a11 * m2.a11 + m1.a12 * m2.a21,
        m1.a11 * m2.a12 + m1.a12 * m2.a22,
        m1.a21 * m2.a11 + m1.a22 * m2.a21,
        m1.a21 * m2.a12 + m1.a22 * m2.a22
    };
}




// Дерево отрезков с операцией произведения матриц
class segtree {
private:
    matrix2x2 tree[MAX_SIZE + 5LL];
    lli size;
    lli mod;

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        return;
    }

    void build(const matrix2x2 *arr, lli sz, lli x, lli lx, lli rx) {
        if (rx - lx == 1LL) {
            if (lx < sz) {
                tree[x] = arr[lx];
                tree[x].mod_eq(mod);
            }
            return;
        }

        lli mid = (lx + rx) / 2LL;
        build(arr, sz, 2LL * x + 1LL, lx, mid);
        build(arr, sz,  2LL * x + 2LL, mid, rx);
        tree[x] = prod(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
        tree[x].mod_eq(mod);
        return;
    }

    void build(const matrix2x2 *arr, lli sz, lli _mod) {
        init(sz);
        mod = _mod;
        build(arr, sz, 0LL, 0LL, size);
        return;
    }

    matrix2x2 segment_prod(lli l, lli r, lli x, lli lx, lli rx) {
        if (rx <= l or r <= lx)
            return E;
        if (l <= lx and rx <= r)
            return tree[x];
        
        lli mid = (lx + rx) / 2LL;
        matrix2x2 sp1 = segment_prod(l, r, 2LL * x + 1LL, lx, mid),
                  sp2 = segment_prod(l, r, 2LL * x + 2LL, mid, rx);
        
        matrix2x2 result = prod(sp1, sp2);
        result.mod_eq(mod);
        return result;
    }

    matrix2x2 segment_prod(lli l, lli r) {
        return segment_prod(l, r, 0LL, 0LL, size);
    }
};




lli d;
lli N;
matrix2x2 A[MAX_SIZE + 5LL];
lli M;
segtree st;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> d >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        A[i].input();
    st.build(A, N, d);

    while (M--) {
        lli l,
            r;
        cin >> l >> r; --l;
        st.segment_prod(l, r).print();
    }
    
    return;
}