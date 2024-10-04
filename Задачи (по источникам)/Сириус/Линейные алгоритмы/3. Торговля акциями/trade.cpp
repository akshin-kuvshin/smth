// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define value   first
#define ind     second
#define NON_DEF -1LL

const lli MAX_SIZE = (lli)1e5 + 5LL,
          INF = (lli)1e18;

lli N,
    X,
    A[MAX_SIZE];
plli pref_min[MAX_SIZE];
lli B[MAX_SIZE];
lli sell_ind = NON_DEF,
    buy_ind = NON_DEF,
    result;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> X;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)N; ++i)
        cin >> B[i];
    result = X;
    
    pref_min[0] = mp(INF, NON_DEF);
    for (int i = 0; i < (int)N; ++i) {
        if (A[i] < pref_min[i].value)
            pref_min[i + 1] = mp(A[i], i);
        else
            pref_min[i + 1] = pref_min[i];
    }

    // Начинаем с 1, потому что мы не можем продать акции в первый день,
    // ведь их у нас нет, а покупать и продавать в один и тот же день нельзя.
    //
    // P.S.: сдал задачу не сразу, потому что реально сглупил при написании условия if-а.
    for (int i = 1; i < (int)N; ++i)
        if (X + (B[i] - pref_min[i].value) * (X / pref_min[i].value) > result) {
            sell_ind = pref_min[i].ind + 1LL;
            buy_ind = (lli)i + 1LL;
            result = X + (B[i] - pref_min[i].value) * (X / pref_min[i].value);
        }
    
    cout << result << '\n' << sell_ind << ' ' << buy_ind << '\n';
    return;
}
