// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

// Сдал задачу только со 2-ой попытки, потому что неправильно задал константу,
// которую нужно вывести в случае отсутствия ответа.
#define NO_ANS  0LL

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    K,
    M;
lli A[MAX_SIZE],
    pref_sum[MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K >> M;
    ++K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    pref_sum[0] = 0LL;
    for (int i = 0; i < (int)N; ++i)
        pref_sum[i + 1] = pref_sum[i] + A[i];
    
    for (int i = 0; i + (int)K <= (int)N; ++i)
        if (pref_sum[i + (int)K] - pref_sum[i] == M) {
            cout << (i + 1) << '\n';
            return;
        }
    
    cout << NO_ANS << '\n';
    return;
}
