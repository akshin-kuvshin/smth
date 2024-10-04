// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N;

void solve();
bool is_prime(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
	cin >> N;
	cout << (is_prime(N) ? "YES" : "NO") << '\n';	
    return;
}

bool is_prime(lli num) {
	for (lli d = 2LL; d * d <= num; ++d)
		if (num % d == 0LL)
			return false;
	return true;
}

