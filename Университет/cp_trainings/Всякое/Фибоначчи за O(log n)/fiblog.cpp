// author: Danila "akshin_" Axyonov

/*
Алгоритм основан на следующем интересном соотношении (далее речь идёт не об определителях, а о матрицах):
|0 1| * |fib(n - 2)| = |       fib(n - 1)      | = |fib(n - 1)|
|1 1|   |fib(n - 1)|   |fib(n - 2) + fib(n - 1)|   |  fib(n)  |
Тогда:
|0 1| ^ (k - 1) * |fib(0)| = |fib(k - 1)|
|1 1|             |fib(1)|   |  fib(k)  |
*/

// АХУЕТЬ

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

class matrix2x2 {
public:
    lli a11, a12,
        a21, a22;

    matrix2x2(lli __a11, lli __a12, lli __a21, lli __a22) {
        this->a11 = __a11;
        this->a12 = __a12;
        this->a21 = __a21;
        this->a22 = __a22;
        return;
    }
};

class vec {
public:
    lli a1,
        a2;

    vec(lli __a1, lli __a2) {
        this->a1 = __a1;
        this->a2 = __a2;
        return;
    }
};

matrix2x2 operator *(const matrix2x2 &A, const matrix2x2 &B) {
    return matrix2x2(
        A.a11 * B.a11 + A.a12 * B.a21,          A.a11 * B.a12 + A.a12 * B.a22,
        A.a21 * B.a11 + A.a22 * B.a21,          A.a21 * B.a12 + A.a22 * B.a22
    );
}

vec operator *(const matrix2x2 &M, const vec &V) {
    return vec(
        M.a11 * V.a1 + M.a12 * V.a2,
        M.a21 * V.a1 + M.a22 * V.a2
    );
}

void solve();
matrix2x2 mat_pow(const matrix2x2&, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli N;
    cin >> N;
    if (!N) { // N == 0LL
        cout << "0\n";
        return;
    }
    matrix2x2 M = matrix2x2(0LL, 1LL,
                            1LL, 1LL);
    M = mat_pow(M, N - 1LL);
    vec res = M * vec(0LL,
                      1LL);
    cout << res.a2 << '\n';    
    return;
}

matrix2x2 mat_pow(const matrix2x2 &M, lli K) {
    if (!K) // K == 0LL
        return matrix2x2(1LL, 0LL,
                         0LL, 1LL);
    matrix2x2 tmp = mat_pow(M, K >> 1);
    matrix2x2 res = tmp * tmp;
    if (K & 1LL) res = res * M;
    return res;
}
