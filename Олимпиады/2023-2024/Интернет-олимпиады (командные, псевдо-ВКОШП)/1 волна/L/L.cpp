// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

lli N;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;

    // Проверка на нулевой сдвиг
    lli seg_1,
        seg_N;
    cout << "? " << 1 << endl;
    cin >> seg_1;
    cout << "? " << N << endl;
    cin >> seg_N;
    if (seg_1 < seg_N) {
        cout << "! 0\n";
        return;
    }

    // инвариантно, что неупорядоченность (пара a[i], a[i + 1] такая, что a[i] > a[i + 1]) находится на отрезке [l, r]
    lli l = 1LL,
        r = N;
    lli seg_l = seg_1,
        seg_mid = -1LL;
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        
        if (seg_l == -1LL) {
            cout << "? " << l << endl;
            cin >> seg_l;
        } else if (seg_mid == -1LL) {
            cout << "? " << mid << endl;
            cin >> seg_mid;
        }

        if (seg_l < seg_mid) { // неупорядоченности нет
            l = mid;
            seg_l = seg_mid;
            seg_mid = -1LL;
        } else {
            r = mid;
            seg_mid = -1LL;
        }
    }

    cout << "! " << (N - l) << '\n';
    return;
}
