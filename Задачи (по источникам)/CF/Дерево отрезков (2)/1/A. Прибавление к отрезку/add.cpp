// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)5e5;

class segtree {
private:
	lli tree[MAX_SIZE];
	lli size;

public:
	void init(lli original_size) {
		size = 1LL;
		while (size < original_size)
			size <<= 1;
		fill(tree, tree + 2LL * size, 0LL);
		return;
	}
	
	void add(lli l, lli r, lli val, lli x, lli lx, lli rx) {
		if (rx <= l or r <= lx)
			return;
		if (l <= lx and rx <= r) {
			tree[x] += val;
			return;
		}
		
		lli mid = (lx + rx) >> 1;
		add(l, r, val, 2LL * x + 1LL, lx, mid);
		add(l, r, val, 2LL * x + 2LL, mid, rx);
		return;
	}
	
	void add(lli l, lli r, lli val) {
		add(l, r, val, 0LL, 0LL, size);
		return;
	}
	
	lli get(lli i, lli x, lli lx, lli rx) {
		if (rx - lx == 1LL)
			return tree[x];
		
		lli mid = (lx + rx) >> 1;
		if (i < mid)
			return tree[x] + get(i, 2LL * x + 1LL, lx, mid);
		return tree[x] + get(i, 2LL * x + 2LL, mid, rx);
	}
	
	lli get(lli i) {
		return get(i, 0LL, 0LL, size);
	}
};

lli N,
	Q;
segtree st;

void solve() {
	cin >> N >> Q;
	st.init(N);
	
	while (Q--) {
		lli cmd;
		cin >> cmd;
		
		if (cmd == 1LL) {
			lli _l,
				_r,
				_val;
			cin >> _l >> _r >> _val;
			st.add(_l, _r, _val);
		} else { // cmd == 2LL
			lli i;
			cin >> i;
			cout << st.get(i) << '\n';
		}
	}
	
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
