// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using lli = long long int;
using ulli = unsigned long long int;

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::setw;
using std::to_string;
using std::vector;

ulli C_recursive(ulli n, ulli k, vector<vector<ulli>>& cache);

int main() {
    cout << "\tWelcome to program that counts C(n, k)!" << endl;

    lli n, k;
    cout << "Enter (n):" << endl
         << "> ";
    cin >> n;
    cout << "Enter (k):" << endl
         << "> ";
    cin >> k;

    if (n < 0LL or k < 0LL) {
        cerr << endl
             << "(!) ERROR: (n) and (k) must be nonnegative." << endl;
        exit(2);
    }
    if (n < k) {
        cerr << endl
             << "(!) ERROR: (n) must be greater than (k)." << endl;
        exit(2);
    }

    vector<vector<ulli>> triangle(n + 1LL, vector<ulli>(n + 1LL));
    for (int i = 0; i <= (int)n; ++i)
        for (int j = 0; j <= i; ++j)
            triangle[i][j] = C_recursive(i, j, triangle);
    
    cout << endl
         << "Pascal's triangle:" << endl;
    int width = (int)to_string(triangle[n][n / 2LL]).size() + 1;
    for (int i = 0; i <= (int)n; ++i) {
        for (int _ = 0; _ < ((int)n - i) * (width / 2); ++_)
            cout << ' ';
        for (int j = 0; j <= i; ++j)
            cout << setw(width) << triangle[i][j];
        cout << endl;
    }

    cout << endl
         << "\tC(" << n << ", " << k << ") = " << triangle[n][k] << endl;
    
    return 0;
}

ulli C_recursive(ulli n, ulli k, vector<vector<ulli>>& cache) {
    if (cache[n][k] == 0ULL) {
        if (k == 0ULL or k == n)
            cache[n][k] = 1ULL;
        else {
            ulli c1 = C_recursive(n - 1ULL, k - 1ULL, cache),
                 c2 = C_recursive(n - 1ULL, k, cache);
            if (ULLONG_MAX - c1 < c2) {
                cerr << endl
                     << "(!) ERROR: overflow happend during counting Pascal's triangle." << endl;
                exit(1);
            }
            cache[n][k] = c1 + c2;
        }
    }
    return cache[n][k];
}
