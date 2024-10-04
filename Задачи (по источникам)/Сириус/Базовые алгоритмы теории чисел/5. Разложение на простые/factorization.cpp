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

void solve();
void factorize(lli, map<lli, lli>&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
	cin >> N;
	
	factorize(N, m);
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it != m.begin())
			cout << '*';
		cout << it->first;
		if (it->second > 1LL)
			cout << '^' << it->second;
	}
	cout << '\n';
	
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

