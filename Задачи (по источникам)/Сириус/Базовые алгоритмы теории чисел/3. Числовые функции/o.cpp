// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N;
plli ans;

void solve();
plli o(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
	cin >> N;
	ans = o(N);
	cout << ans.first << ' ' << ans.second << '\n';	
    return;
}

plli o(lli num) {
	plli result = mp(0LL, 0LL);
	for (lli d = 1LL; d * d <= num; ++d) {
		if (num % d != 0LL)
			continue;
		
		if (d * d == num) {
			++result.first;
			result.second += d;
			continue;
		}
		result.first += 2LL;
		result.second += d + num / d;
	}
	return result;
}

