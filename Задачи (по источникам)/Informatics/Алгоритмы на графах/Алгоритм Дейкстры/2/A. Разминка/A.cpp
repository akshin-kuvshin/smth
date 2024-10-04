// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N;
plli current;
lli _max = 0LL,
    _max_ind = -1LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= (int)N; ++i) {
        cin >> current.first >> current.second;
        if (current.first > _max and current.second == 1LL) {
            _max = current.first;
            _max_ind = (lli)i;
        }
    }
    cout << _max_ind << '\n';
    return;
}
