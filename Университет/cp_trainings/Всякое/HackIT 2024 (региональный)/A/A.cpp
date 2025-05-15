// author: Danila "akshin_" Axyonov

#include <iostream>
#include <unordered_map>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;

    unordered_map<lli, lli> a,
                            b;
    for (int i = 0; i < (int)n; ++i) {
        lli ai;
        cin >> ai;
        ++a[ai];
    }
    for (int i = 0; i < (int)n; ++i) {
        lli bi;
        cin >> bi;
        ++b[bi];
    }

    lli a_ans,
        b_ans;
    for (auto [ai, cnt] : a)
        if (b[ai] < cnt) {
            a_ans = ai;
            break;
        }
    for (auto [bi, cnt] : b)
        if (a[bi] < cnt) {
            b_ans = bi;
            break;
        }
    cout << a_ans << ' ' << b_ans << '\n';    
    return;
}
