// author: Danila "akshin_" Axyonov
// FUCKING BULLSHIT

#include <iostream>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

lli Q;
lli N,
    K,
    num;
multiset<lli> A;
multiset<lli> mono;
set<lli> unique;
bool red_flag;
lli ans = -INF;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    A.clear(); mono.clear(); unique.clear(); ans = -INF;

    cin >> N >> K;
    while (N--) {
        cin >> num;
        A.insert(num);
    }

    while (not A.empty()) {
        red_flag = false;
        if (unique.empty()) {
            num = *A.begin();
            A.erase(A.begin());
            mono.insert(num);
            unique.insert(num);
        }
        while (not A.empty() and (lli)unique.size() <= K) {
            num = *A.begin();
            if (num != *(--unique.end()) and num - 1LL != *(--unique.end())) {
                red_flag = true;
                break;
            }
            A.erase(A.begin());
            mono.insert(num);
            unique.insert(num);
        }

        if (red_flag) {
            ans = max(ans, (lli)mono.size());
            mono.clear();
            unique.clear();
        } else { // not red_flag
            if ((lli)unique.size() > K) {
                ans = max(ans, (lli)mono.size() - 1LL);
                num = *unique.begin();
                mono.erase(num);
                unique.erase(num);
            } else { // A.empty() and (lli)unique.size() <= K
                ans = max(ans, (lli)mono.size());
                break;
            }
        }
    }

    cout << ans << '\n';
    return;
}
