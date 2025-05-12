// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>

#define NOT_DEFINED -1ULL

using lli = long long int;
using ulli = unsigned long long int;

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

ulli Stirling2_recursive(ulli n, ulli k, vector<vector<ulli>>& cache);
ulli Stirling2_nonrecursive(ulli n, ulli k);
ulli C(ulli n, ulli k);
ulli _pow(ulli base, ulli ptr);
void overflow_exit(const string& source);

int main() {
    cout << "\tWelcome to program that counts Stirling2(n, k)!" << endl;

    lli n, k;
    cout << "Enter (n):" << endl
         << "> ";
    cin >> n;
    cout << "Enter (k):" << endl
         << "> ";
    cin >> k;

    if (n <= 0LL or k <= 0LL) {
        cerr << endl
             << "(!) ERROR: (n) and (k) must be positive." << endl;
        exit(2);
    }
    if (n < k) {
        cerr << endl
             << "(!) ERROR: (n) must be greater than (k)." << endl;
        exit(2);
    }

    vector<vector<ulli>> cache(n + 1LL, vector<ulli>(k + 1LL, NOT_DEFINED));
    ulli res_recursive = Stirling2_recursive(n, k, cache);
    cout << endl
         << "\tStirling2_recursive(" << n << ", " << k << ") = " << res_recursive << '.' << endl;
    
    ulli res_nonrecursive = Stirling2_nonrecursive(n, k);
    cout << "\tStirling2_nonrecursive(" << n << ", " << k << ") = " << res_nonrecursive << '.' << endl;
    
    return 0;
}

ulli Stirling2_recursive(ulli n, ulli k, vector<vector<ulli>>& cache) {
    if (cache[n][k] == NOT_DEFINED) {
        if (n == 0ULL and k == 0ULL)
            return 1ULL;
        if (n == 0ULL or k == 0ULL)
            return 0ULL;
        if (n == k)
            return 1ULL;
        
        ulli s1 = Stirling2_recursive(n - 1ULL, k - 1ULL, cache),
             s2 = Stirling2_recursive(n - 1ULL, k, cache);

        if (ULLONG_MAX / s2 < k or ULLONG_MAX - s2 * k < s1) {
            cerr << endl
                 << "(!) ERROR: overflow happened during counting Stirling2_recursive(" << n << ", " << k << ")." << endl;
            exit(1);
        }

        cache[n][k] = s1 + k * s2;
    }
    return cache[n][k];
}

ulli Stirling2_nonrecursive(ulli n, ulli k) {
    ulli res = 0ULL;
    bool neg = false;

    ulli ki = 0ULL;
    bool plus = true;
    while (ki <= k) {
        ulli c = C(k, ki),
             p = _pow(ki, n);
        
        if (ULLONG_MAX / c < p) {
            cerr << endl
                 << "(!) ERROR: overflow happened during counting Stirling2_nonrecursive(" << n << ", " << k << ")." << endl;
            exit(1);
        }

        if (neg xor plus) {
            if (ULLONG_MAX - res < c * p) {
                cerr << endl
                     << "(!) ERROR: overflow happened during counting Stirling2_nonrecursive(" << n << ", " << k << ")." << endl;
                exit(1);
            }
            res += c * p;
        } else if (not neg and not plus) {
            if (res < c * p) {
                res = c * p - res;
                neg = true;
            } else // res >= c * p
                res -= c * p;
        } else { // neg and plus
            if (res <= c * p) {
                res = c * p - res;
                neg = false;
            } else // res > c * p
                res -= c * p;
        }

        ++ki;
        plus = not plus;
    }

    for (ki = 2ULL; ki <= k; ++ki)
        res /= ki;
    
    return res;
}

ulli C(ulli n, ulli k) {
    ulli res = 1ULL;
    for (ulli ni = 2ULL, denom1 = 2ULL, denom2 = 2ULL; ni <= n; ++ni) {
        if (ULLONG_MAX / res < ni)
            overflow_exit("C(" + to_string(n) + ", " + to_string(k) + ")");
        res *= ni;

        while (denom1 <= k and res % denom1 == 0ULL)
            res /= denom1++;
        while (denom2 <= n - k and res % denom2 == 0ULL)
            res /= denom2++;
    }
    return res;
}

ulli _pow(ulli base, ulli ptr) {
    ulli base0 = base,
         ptr0 = ptr;
    ulli res = 1ULL;
    while (ptr > 0ULL) {
        if (ptr % 2ULL == 1ULL) {
            if (ULLONG_MAX / res < base)
                overflow_exit("A_with_rep(" + to_string(base0) + ", " + to_string(ptr0) + ")");
            res *= base;
        }
        if (ULLONG_MAX / base < base)
            overflow_exit("A_with_rep(" + to_string(base0) + ", " + to_string(ptr0) + ")");
        base *= base;
        ptr /= 2LL;
    }
    return res;
}

void overflow_exit(const string& source) {
    cerr << endl
         << "(!) ERROR: overflow happened during counting " << source << '.' << endl;
    exit(1);
}
