// author:		Danila "akshin_" Axyonov
// password:	28092025

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

#define pb(_elem)				push_back(_elem)
#define mp(_first, _second)		make_pair(_first, _second)

const lli MAX_SIZE = (lli)1e5 + 1LL,
		  MOD[] = {1000000007LL, 998244353LL};
lli FACT[2][MAX_SIZE],
	INV_FACT[2][MAX_SIZE];

void solve();
lli count_greater(const string& a, int j, vector<lli>& cnt, lli mod2, int i);
lli count_all(vector<lli>& cnt, lli mod2, int i);
lli inv(lli a, int i);
lli mod_pow(lli base, lli ptr, int i);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 2; ++i) {
		FACT[i][0] = 1LL;
		INV_FACT[i][0] = inv(FACT[i][0], i);
		for (lli k = 1LL; k < MAX_SIZE; ++k) {
			FACT[i][k] = (FACT[i][k - 1LL] * k) % MOD[i];
			INV_FACT[i][k] = inv(FACT[i][k], i);
		}
	}

	solve();

	return 0;
}

void solve() {
	string a;
	cin >> a;

	vector<lli> cnt(10);
	for (char c : a)
		++cnt[c - '0'];

	lli mod2 = 1LL - (lli)(a.back() - '0') % 2LL;
	
	for (int i = 0; i < 2; ++i)
		cout << count_greater(a, 0, cnt, mod2, i) << ' ';
	cout << '\n';
	return;
}

lli count_greater(const string& a, int j, vector<lli>& cnt, lli mod2, int i) {
	if (j == (int)a.size())
		return 0LL;

	lli a0 = (lli)(a[j] - '0');
	--cnt[a0];
	lli S = count_greater(a, j + 1, cnt, mod2, i);
	++cnt[a0];

	for (lli d = a0 + 1LL; d < 10LL; ++d) { // d - цифра в начале
		if (not cnt[d])
			continue;

		--cnt[d];
		S = (S + count_all(cnt, mod2, i)) % MOD[i];
		++cnt[d];
	}

	return S;
}

lli count_all(vector<lli>& cnt, lli mod2, int i) {
	lli S = 0LL;
	for (lli d = 0LL; d < 10LL; ++d) { // d - цифра в конце
		if (d % 2LL != mod2)
			continue;
		if (not cnt[d])
			continue;

		--cnt[d];

		lli cnt_S = 0LL;
		for (lli cnti : cnt)
			cnt_S += cnti;

		lli result = FACT[i][cnt_S];
		for (lli cnti : cnt)
			result = (result * INV_FACT[i][cnti]) % MOD[i];
		S = (S + result) % MOD[i];

		++cnt[d];
	}
	return S;
}

lli inv(lli a, int i) {
	return mod_pow(a, MOD[i] - 2LL, i);
}

lli mod_pow(lli base, lli ptr, int i) {
	if (not ptr)
		return 1LL;
	if (ptr & 1LL)
		return (base * mod_pow(base, ptr - 1LL, i)) % MOD[i];
	lli half = mod_pow(base, ptr >> 1, i);
	return (half * half) % MOD[i];
}

