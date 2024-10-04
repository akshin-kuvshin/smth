// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE],
    _sum,
    for_each;
lli partial_sum;
vector<lli> parts;
lli M;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        _sum += A[i];

        if (!A[i]) {
            // Добавляем даже нули (не делаем проверку на них),
            // потому что программа будет пропускать их, как хорошие "части".
            parts.pb(partial_sum);
            partial_sum = 0LL;
        } else
            partial_sum += A[i];
    }
    // Здесь см. комментарий выше.
    parts.pb(partial_sum);
    partial_sum = 0LL;

    if (_sum % M) {
        cout << "NO\n";
        return;
    }
    for_each = _sum / M;
    
    for (lli part : parts)
        if (part % for_each) {
            cout << "NO\n";
            return;
        }
    
    cout << "YES\n";
    return;
}
