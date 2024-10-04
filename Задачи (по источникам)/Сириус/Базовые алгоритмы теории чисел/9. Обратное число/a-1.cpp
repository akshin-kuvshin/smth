// author: Danila "akshin_" Aksionov

#include <iostream>
#include <map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli a,
	m,
	ans;

void solve();
lli gcd_R(lli, lli);
lli get_phi(lli);
void factorize(lli, map<lli, lli>&);
lli _pow(lli, lli);
lli mod_pow(lli, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
	cin >> m >> a;
	
	if (gcd_R(a, m) > 1LL) {
		cout << "-1\n";
		return;
	}
	
	lli phi = get_phi(m);
	ans = mod_pow(a, phi - 1LL, m);
	cout << ans << '\n';
    return;
}

lli gcd_R(lli x, lli y) {
	return ((x && y) ? gcd_R(y, x % y) : (x | y));
}

lli get_phi(lli num) {
	map<lli, lli> divs;
	factorize(num, divs);
	
	lli phi = 1LL;
	for (plli p : divs) {
		lli x = _pow(p.first, p.second - 1LL);
		phi *= x * (p.first - 1LL);
	}
	
	return phi;
}

void factorize(lli num, map<lli, lli> &divs) {
	for (lli d = 2LL; d * d <= num; ++d)
		while (num % d == 0LL) {
			num /= d;
			++divs[d];
		}
	if (num > 1LL)
		++divs[num];
	return;
}

lli _pow(lli base, lli ptr) {
	if (ptr == 0LL)
		return 1LL;
	if (ptr % 2LL == 0LL) {
		lli half = _pow(base, ptr / 2LL);
		return half * half;
	}
	return base * _pow(base, ptr - 1LL);
}

lli mod_pow(lli base, lli ptr, lli mod) {
	if (ptr == 0LL)
		return 1LL;
	if (ptr % 2LL == 0LL) {
		lli half = mod_pow(base, ptr / 2LL, mod);
		return (half * half) % mod;
	}
	return (base * mod_pow(base, ptr - 1LL, mod)) % mod;
}

