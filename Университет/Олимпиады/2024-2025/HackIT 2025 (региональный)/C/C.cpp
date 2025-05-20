// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

const lli N = 5LL;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
	vector<vector<lli>> a(N, vector<lli>(N));
	vector<lli> row_sum(N);
	for (int i = 0; i < (int)N; ++i)
		for (int j = 0; j < (int)N; ++j) {
			cin >> a[i][j];
			row_sum[i] += a[i][j];
		}
	
	string teams = "VITEK";
	vector<pair<lli, char>> b(N);
	for (int i = 0; i < (int)N; ++i)
		b[i] = make_pair(row_sum[i], teams[i]);
	sort(b.begin(), b.end());
	
	lli cnt = 0LL;
	for (char t : teams) {
		vector<lli> six(N);
		lli cur = 4LL,
			ind;
		for (int i = 0; i < (int)N; ++i)
			if (b[i].second == t) {
				six[i] = 5LL;
				ind = (lli)i;
			} else
				six[i] = cur--;
        
		lli _max = 0LL;
		for (int i = 0; i < (int)N; ++i)
			_max = max(_max, b[i].first + six[i]);
		if (b[ind].first + six[ind] == _max) {
			cout << t;
			++cnt;
		}
	}
	if (cnt == N)
		cout << '!';
	cout << '\n';
	return;
}
