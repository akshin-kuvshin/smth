// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

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
    lli N;
    cin >> N;
    vector<char> S(N);
    vector<int> slashes;
    for (int i = 0; i < (int)N; ++i) {
        cin >> S[i];
        if (S[i] == '/')
            slashes.pb(i);
    }

    int ans = 1;
    for (int s_ind : slashes) {
        int i = s_ind,
            j = s_ind;
        do {
            --i; ++j;
        } while (0 <= i and j < (int)N and S[i] == '1' and S[j] == '2');
        int len = j - i - 1;
        ans = max(ans, len);
    }
    cout << ans << '\n';
    return;
}
