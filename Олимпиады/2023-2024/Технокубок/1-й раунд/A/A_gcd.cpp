// author: Danila "akshin_" Aksionov
// Это второе решение. Оно более точное, т.к. тут абсолютно нет деления. Считаем два потенциальных q геометрической прогресси в виде дробей, сокращаем дроби и считаем, что они равны тогда и только тогда, когда равны их числители и равны знаменатели.

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
lli gcd_R(lli, lli);

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
    
    lli m1 = A[1],
        n1 = A[0],
        m2 = A[2],
        n2 = A[1];
    lli gcd_1 = gcd_R(m1, n1),
        gcd_2 = gcd_R(m2, n2);
    m1 /= gcd_1;
    n1 /= gcd_1;
    m2 /= gcd_2;
    n2 /= gcd_2;
    if (m1 == m2 and n1 == n2) {
        cout << "G " << A[0] << ' ' << A[1] << ' ' << A[2] << '\n';
        return;
    }
    
    cout << "No\n";
    return;
}

lli gcd_R(lli x, lli y) {
    return ((x && y) ? gcd_R(y, x % y) : (x | y));
}
