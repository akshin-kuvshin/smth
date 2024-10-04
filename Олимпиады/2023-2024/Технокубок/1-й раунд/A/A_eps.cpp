// author: Danila "akshin_" Aksionov
// Это первое решение. Вся проблема была в том, что я брал слишком большой EPS.
// Вывод: при делении целых чисел вполне хорошо работает EPS = 1e-12.

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N = 3LL;
const double EPS = 1e-12;

lli A[N];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> A[0] >> A[1] >> A[2];
    sort(A, A + N);

    if (A[2] - A[1] == A[1] - A[0]) {
        cout << "A " << A[0] << ' ' << A[1] << ' ' << A[2] << '\n';
        return;
    }
    if (abs((double)A[2] / (double)A[1] - (double)A[1] / (double)A[0]) < EPS) {
        cout << "G " << A[0] << ' ' << A[1] << ' ' << A[2] << '\n';
        return;
    }
    
    cout << "No\n";
    return;
}
