#include <iostream>
#include <algorithm>
#define a 0LL
#define b 1LL
#define c 2LL
#define BIG 1000000LL
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 100000LL;

lli Q;
lli N, // кол-во прямых
    M, // кол-во парабол
    k[MAX_SIZE + 5LL], // коэф-ты прямых
    par[3LL][MAX_SIZE + 5LL]; // коэф-ты парабол

void solve();
lli bs_greater(lli, lli, lli); // найти минимальный индекс i такой, что elem <= k[i]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--) {
        solve();
    }
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> k[i];
    for (int i = 0; i < (int)M; ++i)
        cin >> par[a][i] >> par[b][i] >> par[c][i];
    
    sort(k, k + N);
    
    // перебираем все параболы
    for (int i = 0; i < (int)M; ++i) {
        // выбираем коэффициент такой, что |b - k| минимален
        lli k2 = bs_greater(0LL, N, -par[b][i]),
            k4 = bs_greater(0LL, N, par[b][i]);
        lli k1 = k2 - 1LL,
            k3 = k4 - 1LL;
        // а также проверяем крайние элементы в отсортированном k[] (опыт показывает, что надо)
        lli k5 = 0LL,
            k6 = N - 1LL;

        if (0LL <= k1 and k1 < N) {
            lli D = (par[b][i] - k[k1]) * (par[b][i] - k[k1]) - 4LL * par[a][i] * par[c][i];
            if (D < 0LL) {
                cout << "YES\n" << k[k1] << '\n';
                continue;
            }
        }
        if (0LL <= k2 and k2 < N) {
            lli D = (par[b][i] - k[k2]) * (par[b][i] - k[k2]) - 4LL * par[a][i] * par[c][i];
            if (D < 0LL) {
                cout << "YES\n" << k[k2] << '\n';
                continue;
            }
        }
        if (0LL <= k3 and k3 < N) {
            lli D = (par[b][i] - k[k3]) * (par[b][i] - k[k3]) - 4LL * par[a][i] * par[c][i];
            if (D < 0LL) {
                cout << "YES\n" << k[k3] << '\n';
                continue;
            }
        }
        if (0LL <= k4 and k4 < N) {
            lli D = (par[b][i] - k[k4]) * (par[b][i] - k[k4]) - 4LL * par[a][i] * par[c][i];
            if (D < 0LL) {
                cout << "YES\n" << k[k4] << '\n';
                continue;
            }
        }
        if (0LL <= k5 and k5 < N) {
            lli D = (par[b][i] - k[k5]) * (par[b][i] - k[k5]) - 4LL * par[a][i] * par[c][i];
            if (D < 0LL) {
                cout << "YES\n" << k[k5] << '\n';
                continue;
            }
        }
        if (0LL <= k6 and k6 < N) {
            lli D = (par[b][i] - k[k6]) * (par[b][i] - k[k6]) - 4LL * par[a][i] * par[c][i];
            if (D < 0LL) {
                cout << "YES\n" << k[k6] << '\n';
                continue;
            }
        }

        cout << "NO\n";
    }

    return;
}

lli bs_greater(lli L, lli R, lli elem) {
    if (L >= R) return BIG;
    if (R - L == 1LL) {
        if (elem <= k[L])
            return L;
        else
            return BIG;
    }

    lli mid = (L + R) / 2LL;
    if (elem < k[mid]) {
        return min(mid, bs_greater(L, mid, elem));
    }
    if (elem == k[mid]) {
        return mid;
    }
    return bs_greater(mid, R, elem);
}
