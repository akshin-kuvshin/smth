// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define start				first
#define len					second

const lli MAX_SIZE = (lli)1e6;

lli N;
pair<lli, lli> cur;
lli K,
	t[MAX_SIZE]; // в какой момент времени освободится i-тая касса

int main() {
	cin >> N >> K;
	
	while (N--) {
		cin >> cur.start >> cur.len;
		
		lli ind = 0LL,
			cur_t = cur.start + 1LL + max(t[0] - cur.start - 1LL, 0LL) + cur.len + 1LL;
		for (lli i = 1LL; i < K; ++i)
			if (cur.start + (i + 1LL) + max(t[i] - cur.start - (i + 1LL), 0LL) + cur.len + (i + 1LL) < cur_t) {
				cur_t = cur.start + (i + 1LL) + max(t[i] - cur.start - (i + 1LL), 0LL) + cur.len + (i + 1LL);
				ind = i;
			}
		cout << (ind + 1LL) << '\n';
		
		t[ind] = max(t[ind], cur.start + (ind + 1LL)) + cur.len;
	}
	
	return 0;
}
