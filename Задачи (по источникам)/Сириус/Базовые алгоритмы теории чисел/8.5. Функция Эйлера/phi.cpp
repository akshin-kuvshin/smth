// author: Danila "akshin_" Aksionov

#include <iostream>
#include <map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N;
map<lli, lli> m;
lli phi;

void solve();
void factorize(lli, map<lli, lli>&);
lli _pow(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
	cin >> N;
	factorize(N, m);
	
	phi = 1LL;
	for (plli p : m) {
		lli x = _pow(p.first, p.second - 1LL);
		phi *= x * (p.first - 1LL);
	}
	
	cout << phi << '\n';
    return;
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

