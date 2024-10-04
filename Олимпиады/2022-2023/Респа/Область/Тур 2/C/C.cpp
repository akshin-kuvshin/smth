// FINAL (18/100)

#include <iostream>
#include <algorithm>
#define UNDEFINED -1LL
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 500000LL;

lli N,
	M,
	A[MAX_SIZE + 5LL],
	prefix_xor[MAX_SIZE + 5LL];
lli ind;
lli ans;

lli find_first_bigger_or_equal(lli);
lli find_first_bigger_or_equal(lli, lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	for (int i = 0; i < (int)N; ++i)
		cin >> A[i];
	sort(A, A + N);
	for (int i = 0; i < (int)N; ++i)
		prefix_xor[i + 1] = prefix_xor[i] ^ A[i];
	
	for (lli d = 1LL; d <= A[N - 1LL]; ++d) {
		ind = find_first_bigger_or_equal(d);
		ind = ((ind == UNDEFINED) ? N : ind);
		
		ans = prefix_xor[ind] ^ prefix_xor[0];
		for (int i = (int)ind; i < (int)N; ++i)
			ans ^= (A[i] % d);
		cout << ans << ' ';
	}
	for (lli d = A[N - 1LL] + 1LL; d <= M; ++d)
		cout << (prefix_xor[N] ^ prefix_xor[0]) << ' ';
	cout << '\n';
	
	return 0;
}

lli find_first_bigger_or_equal(lli elem) {
	return find_first_bigger_or_equal(0LL, N - 1LL, elem);
}

// �� ������� [L, R]
lli find_first_bigger_or_equal(lli L, lli R, lli elem) {
	if (L > R)
		return UNDEFINED;
	
	lli mid = (L + R) / 2LL;
	if (A[mid] < elem)
		return find_first_bigger_or_equal(mid + 1LL, R, elem);
	
	// else if (elem <= A[mid])
	lli _try = find_first_bigger_or_equal(L, mid - 1LL, elem);
	if (_try == UNDEFINED)
		return mid;
	return _try;
}
