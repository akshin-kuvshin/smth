// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;

vector<lli> S1_divs;
set<lli> S2_divs;

lli bs(lli, lli);
bool f(lli, lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	lli S1,
		S2;
	cin >> S1 >> S2;
	
	for (lli d = 1LL; d * d <= S1; ++d)
		if (S1 % d == 0LL) {
			S1_divs.push_back(d);
			S1_divs.push_back(S1 / d);
		}
	
	for (lli d = 1LL; d * d <= S2; ++d)
		if (S2 % d == 0LL) {
			S2_divs.insert(d);
			S2_divs.insert(S2 / d);
		}
	
	lli ans = bs(S1, S2);
	cout << ans << '\n';
	
	return 0;
}

lli bs(lli S1, lli S2) {
	lli l = 0LL,
		r = (lli)1e18 + 1LL;
	while (l + 1LL < r) {
		lli mid = (l + r) >> 1;
		if (f(S1, S2, mid))
			r = mid;
		else
			l = mid;
	}
	return r;
}

bool f(lli S1, lli S2, lli x) {
	for (lli a : S1_divs) {
		if (a > x)
			continue;
		lli b = S1 / a;
		if (b > x)
			continue;
		
		lli da = x - a,
			db = x - b;
		
		auto c = S2_divs.upper_bound(da),
			 d = S2_divs.upper_bound(db);
		
		if (c != S2_divs.begin()) {
			--c;
			lli e = *c;
			lli f = S2 / e;
			if (f <= x)
				return true;
		}
		if (d != S2_divs.begin()) {
			--d;
			lli e = *d;
			lli f = S2 / e;
			if (f <= x)
				return true;
		}
	}
	
	return false;
}
