#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli N_max = 100000LL;

lli N,
	A[N_max + 5LL];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	cin >> N;
	for (int i = 0; i < (int)N; ++i)
		cin >> A[i];
	
	sort(A, A + N);
	
	cout << A[N - 1LL] << ' ' << A[0] << '\n';
	
	return 0;
}
