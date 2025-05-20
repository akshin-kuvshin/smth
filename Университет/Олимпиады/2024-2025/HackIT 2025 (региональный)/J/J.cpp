// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

void solve();
lli gcd(lli a, lli b);
vector<plli> get_canon(lli x);
void dfs(lli i, const vector<plli>& canon, vector<lli>& alpha, vector<lli>& cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli& ai : a)
        cin >> ai;
    lli k;
    cin >> k;
    
    for (lli& ai : a)
        ai = gcd(ai, k);
    
    vector<lli> cnt(k + 1LL);
    for (lli& ai : a) {
        vector<plli> canon = get_canon(ai);
        vector<lli> alpha(canon.size());
        dfs(0LL, canon, alpha, cnt);
    }
    
    lli ans = 0LL;
    for (lli ai : a) {
        lli x = k / ai;
        ans += cnt[x];
        if (ai % x == 0LL)
            --ans;
    }
    double p = (double)ans / (double)(n * (n - 1LL));
    cout << fixed << setprecision(20) << p << '\n';
	return;
}

lli gcd(lli a, lli b) {
    return ((a && b) ? gcd(b, a % b) : (a | b));
}

vector<plli> get_canon(lli x) {
    vector<plli> res;
    lli d = 2LL;
    while (x > 1LL) {
        lli cnt = 0LL;
        while (x % d == 0LL) {
            x /= d;
            ++cnt;
        }
        if (cnt)
            res.push_back({d, cnt});
        ++d;
    }
    return res;
}

void dfs(lli i, const vector<plli>& canon, vector<lli>& alpha, vector<lli>& cnt) {
    if (i == (lli)canon.size()) {
        lli x = 1LL;
        for (int j = 0; j < (int)canon.size(); ++j)
            for (int _ = 0; _ < (int)alpha[j]; ++_)
                x *= canon[j].first;
        ++cnt[x];
        return;
    }
    
    for (lli j = 0LL; j <= canon[i].second; ++j) {
        alpha[i] = j;
        dfs(i + 1LL, canon, alpha, cnt);
    }
    return;
}
