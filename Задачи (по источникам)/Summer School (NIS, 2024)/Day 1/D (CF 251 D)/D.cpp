// author: Danila "akshin_" Axyonov

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define num                 first
#define amount              second

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE],
    M,
    B[MAX_SIZE];
map<lli, lli> dA,
              dB;
vector<pair<lli, lli>> lA,
                       lB;
lli diff,
    ans;

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
        ++dA[A[i]];
    }
    for (int i = 0; i < (int)M; ++i) {
        cin >> B[i];
        ++dB[B[i]];
    }

    for (auto it = dA.begin(); it != dA.end(); ++it)
        lA.pb(mp(it->num, it->amount));
    reverse(lA.begin(), lA.end());
    for (auto it = dB.begin(); it != dB.end(); ++it)
        lB.pb(mp(it->num, it->amount));
    
    diff = lB.back().num - lA.back().num;
    while (diff > 0LL) {
        if (lA.back().amount <= lB.back().amount) {
            plli tmp = lA.back();
            lA.pop_back();
            lli _num = tmp.num,
                _amount = tmp.amount;

            if (lA.empty()) {
                ans += diff * _amount;
                break;
            }

            lli d = min(diff, lA.back().num - _num);
            diff -= d;
            ans += d * _amount;

            _num += d;
            lA.back().amount += _amount;
        } else { // lA.back().amount > lB.back().amount
            plli tmp = lB.back();
            lB.pop_back();
            lli _num = tmp.num,
                _amount = tmp.amount;

            if (lB.empty()) {
                ans += diff * _amount;
                break;
            }

            lli d = min(diff, _num - lB.back().num);
            diff -= d;
            ans += d * _amount;

            _num -= d;
            lB.back().amount += _amount;
        }
    }
    
    cout << ans << '\n';
    return;
}
