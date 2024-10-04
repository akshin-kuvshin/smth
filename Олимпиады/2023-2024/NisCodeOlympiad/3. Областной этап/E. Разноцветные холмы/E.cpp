// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e2 + 5LL;

lli N;
bool G[MAX_SIZE][MAX_SIZE];
lli color[MAX_SIZE],
	cnt;

int main() {
	cin >> N;
	for (lli i = 0LL; i < N; ++i)
		for (lli j = 0LL; j < N; ++j)
			cin >> G[i][j];
	for (lli i = 0LL; i < N; ++i)
		cin >> color[i];
	
	for (lli i = 0LL; i < N; ++i)
		for (lli j = 0LL; j < i; ++j)
			if (G[i][j] and color[i] != color[j])
				++cnt;
	
	cout << cnt << '\n';
	return 0;
}
