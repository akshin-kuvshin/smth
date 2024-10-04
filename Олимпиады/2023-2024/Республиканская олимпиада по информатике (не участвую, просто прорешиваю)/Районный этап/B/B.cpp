// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)2e5 + 5LL;

lli N,
	A[MAX_SIZE];
lli temir,
	alt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 0; i < (int)(2LL * N); ++i)
		cin >> A[i];
	sort(A, A + 2LL * N);
	
	for (int i = 0; i < (int)N; ++i)
		temir += A[i];
	for (int i = (int)N; i < (int)(2LL * N); ++i)
		alt += A[i];
	
	cout << alt << ' ' << temir << '\n';	
	return 0;
}
