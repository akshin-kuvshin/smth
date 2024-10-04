// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 200000LL;

lli Q;
lli N,
    A[MAX_SIZE + 5LL];
lli answer;

void solve();
lli _count(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--)
        solve();    
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    answer = 0LL;
    
    sort(A, A + N);

    for (int i = (int)N - 1; i >= 0; --i) {
        for (lli d = 1LL; d * d <= A[i]; ++d) {
            if (A[i] % (d * d)) continue;

            lli num1 = A[i] / d / d,
                num2 = A[i] / d;
                // num3 = A;
            
            lli count1 = _count(i, num1),
                count2 = _count(i, num2);
            
            
            if (d == 1LL) {
                lli c = count1;
                answer += c * (c - 1LL) / 2LL * 6LL;
            } else
                answer += count1 * count2;
        }
    }

    cout << answer << '\n';
    return;
}

lli _count(lli _fin, lli _elem) {
    lli ind_l = lower_bound(A, A + _fin, _elem) - A,
        ind_u = upper_bound(A, A + _fin, _elem) - A;
    return ind_u - ind_l;
}
