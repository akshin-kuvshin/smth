// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    string S;
    cin >> S;
    vector<lli> cnt(256);
    for (char c : S)
        ++cnt[c];
    
    string half;
    char mid;
    bool has_mid = false;
    for (char c = 'A'; c <= 'Z'; ++c) {
        while (cnt[c] >= 2LL) {
            half.pb(c);
            cnt[c] -= 2LL;
        }
        if (not has_mid and cnt[c]) {
            mid = c;
            has_mid = true;
        }
    }

    cout << half;
    if (has_mid)
        cout << mid;
    reverse(half.begin(), half.end());
    cout << half << '\n';
        
    return;
}
