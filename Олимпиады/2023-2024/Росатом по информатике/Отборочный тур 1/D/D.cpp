// author: Danila "akshin_" Axyonov
// FINAL VERSION

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e3 + 5LL;

lli N,
    A[MAX_SIZE][MAX_SIZE],
    B[MAX_SIZE][MAX_SIZE];
vector<lli> ns;

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
        for (int j = 0; j < (int)N; ++j)
            cin >> A[i][j];
    
    for (int i = 0; i < (int)N; ++i)
        for (int j = 0; j < (int)N; ++j) {
            if ((i == 0) or (j == 0)
                         or (i == (int)N - 1)
                         or (j == (int)N - 1)) {
                B[i][j] = A[i][j];
                continue;
            }

            ns.clear();
            ns.insert(ns.end(), {
                A[i - 1][j - 1],
                A[i - 1][j],
                A[i - 1][j + 1],
                A[i][j - 1],
                A[i][j],
                A[i][j + 1],
                A[i + 1][j - 1],
                A[i + 1][j],
                A[i + 1][j + 1]
            });
            sort(ns.begin(), ns.end());
            B[i][j] = ns[4];
        }
    
    for (int i = 0; i < (int)N; ++i) {
        for (int j = 0; j < (int)N; ++j)
            cout << B[i][j] << ' ';
        cout << '\n';
    }
    return;
}
