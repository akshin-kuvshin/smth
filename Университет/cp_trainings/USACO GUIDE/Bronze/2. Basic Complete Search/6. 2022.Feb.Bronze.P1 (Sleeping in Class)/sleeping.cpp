// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli q;
    cin >> q;
    while (q--)
        solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    lli s = 0LL;
    for (auto& ai : a) {
        cin >> ai;
        s += ai;
    }

    if (not s) {
        cout << "0\n";
        return;
    }

    lli ans;
    for (lli d = 1LL; d <= s; ++d) {
        if (s % d)
            continue;
        
        bool flag = true;
        lli cur = 0LL;
        for (auto ai : a) {
            cur += ai;
            if (cur > d) {
                flag = false;
                break;
            }
            if (cur == d)
                cur = 0LL;
        }

        if (flag and not cur) {
            ans = n - s / d;
            break;
        }
    }
    
    cout << ans << '\n';
    return;
}
