// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

vector<string> S;
unordered_map<string, lli> M;

void solve();
void dfs(vector<lli>, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli N,
        K;
    cin >> N >> K;
    S.resize(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> S[i];
    
    for (lli d = 0LL; d < N; ++d)
        dfs({d}, N, K);
    
    lli ans = 0LL;
    for (pair<string, lli> p : M)
        if (p.second == 1LL)
            ++ans;
    cout << ans << '\n';
    return;
}

void dfs(vector<lli> A, lli N, lli K) {
    if ((lli)A.size() == K) {
        string code = "";
        for (lli d : A)
            code += S[d];
        ++M[code];
        return;
    }

    for (lli d = 0LL; d < N; ++d) {
        vector<lli> B = A;
        B.pb(d);
        dfs(B, N, K);
    }
    return;
}
