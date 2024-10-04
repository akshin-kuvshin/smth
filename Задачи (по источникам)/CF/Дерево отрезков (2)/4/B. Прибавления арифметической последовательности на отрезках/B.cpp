// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm> // for std::fill
using namespace std;
typedef long long int lli;



const lli MAX_SIZE = (lli)8e5 + 5LL;



class segtree {
private:
	lli op_a1[MAX_SIZE];
	lli op_d[MAX_SIZE];
	lli size;
	
	lli add(lli l, lli r, lli a1, lli d, lli x, lli lx, lli rx) {
		if (rx <= l or r <= lx)
			return 0LL;
		if (l <= lx and rx <= r) {
			op_a1[x] += a1;
			op_d[x] += d;
			return rx - lx;
		}
		
		lli mid = (lx + rx) >> 1;
		lli k = add(l, r, a1, d, 2LL * x + 1LL, lx, mid);
		return k + add(l, r, a1 + k * d, d, 2LL * x + 2LL, mid, rx);
	}
	
	lli get(lli i, lli x, lli lx, lli rx) {
		if (rx - lx == 1LL)
			return op_a1[x];
		
		lli mid = (lx + rx) >> 1,
			res;
		if (i < mid)
			res = get(i, 2LL * x + 1LL, lx, mid);
		else // i >= mid
			res = get(i, 2LL * x + 2LL, mid, rx);
		return res + op_a1[x] + (i - lx) * op_d[x];
	}

public:
	void init(lli original_size) {
		size = 1LL;
		while (size < original_size)
			size <<= 1;
		
		fill(op_a1, op_a1 + 2LL * size, 0LL);
		fill(op_d, op_d + 2LL * size, 0LL);
		
		return;
	}
	
	void add(lli l, lli r, lli a1, lli d) {
		add(l, r, a1, d, 0LL, 0LL, size);
		return;
	}
	
	lli get(lli i) {
		return get(i, 0LL, 0LL, size);
	}
};



lli N;
segtree st;
lli Q,
	cmd;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	st.init(N);
	
	cin >> Q;
	while (Q--) {
		cin >> cmd;
		if (cmd == 1LL) {
			lli l,
				r,
				a1,
				d;
			cin >> l >> r >> a1 >> d;
			st.add(--l, r, a1, d);
		} else {
			lli i;
			cin >> i;
			cout << st.get(--i) << '\n';
		}
	}
	
	return 0;
}
