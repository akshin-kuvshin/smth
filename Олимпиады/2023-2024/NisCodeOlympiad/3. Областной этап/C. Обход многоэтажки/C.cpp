// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e2 + 5LL;

lli N,
	M,
	A[MAX_SIZE][MAX_SIZE];
bool used[MAX_SIZE][MAX_SIZE];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	for (lli i = 0LL; i <= N + 1LL; ++i) {
		if (i == 0LL or i == N + 1LL) {
			fill(used[i], used[i] + M + 2LL, true);
			continue;
		}
		for (lli j = 0LL; j <= M + 1LL; ++j) {
			if (j == 0LL or j == M + 1LL) {
				used[i][j] = true;
				continue;
			}
			cin >> A[i][j];
		}
	}
	
	lli i = N,
		j = M,
		dir = 0LL;
	while (1LL <= i and i <= N and 0 <= j and j <= M and !used[i][j]) {
		cout << A[i][j] << ' ';
		used[i][j] = true;
		
		if (dir == 0LL) {
			if (used[i - 1LL][j]) {
				dir = 1LL;
				--j;
			} else
				--i;
		} else if (dir == 1LL) {
			if (used[i][j - 1LL]) {
				dir = 2LL;
				++i;
			} else
				--j;
		} else if (dir == 2LL) {
			if (used[i + 1LL][j]) {
				dir = 3LL;
				++j;
			} else
				++i;
		} else { // dir == 3LL
			if (used[i][j + 1LL]) {
				dir = 0LL;
				--i;
			} else
				++j;
		}
	}
	
	return 0;
}
