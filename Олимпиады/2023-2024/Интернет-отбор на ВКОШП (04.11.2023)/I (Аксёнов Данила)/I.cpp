#include <iostream>
using namespace std;
typedef long long int lli;

typedef pair<lli, lli> Node;
#define val 					first
#define ind 					second
#define mp(_first, _second) 	make_pair(_first, _second)

Node combine(const Node &n1, const Node &n2) {
	if (n1.val >= n2.val)
		return n1;
	return n2;
}

const lli MAX_SIZE = (lli)2e5 + 5LL;
const Node EMPTY = mp(-1LL, -1LL);





class segtree {
private:
	Node tree[4LL * MAX_SIZE];
	lli size;
	
	void build(lli original_size, lli *arr, lli x, lli lx, lli rx) {
		if (rx - lx == 1LL) {
			if (lx < original_size)
				tree[x] = mp(arr[lx], lx);
			else
				tree[x] = EMPTY;
			return;
		}
		
		lli mid = (lx + rx) >> 1;
		build(original_size, arr, 2LL * x + 1LL, lx, mid);
		build(original_size, arr, 2LL * x + 2LL, mid, rx);
		tree[x] = combine(
			tree[2LL * x + 1LL],
			tree[2LL * x + 2LL]
		);
		return;
	}
	
	Node get_max(lli l, lli r, lli x, lli lx, lli rx) {
		if (rx <= l or r <= lx)
			return EMPTY;
		if (l <= lx and rx <= r)
			return tree[x];
		
		lli mid = (lx + rx) >> 1;
		return combine(
			get_max(l, r, 2LL * x + 1LL, lx, mid),
			get_max(l, r, 2LL * x + 2LL, mid, rx)
		);
	}

public:
	void init(lli original_size, lli *arr) {
		size = 1LL;
		while (size < original_size)
			size <<= 1;
		build(original_size, arr, 0LL, 0LL, size);
		return;
	}
	
	lli get_ind_of_max(lli l, lli r) {
		return get_max(l, r, 0LL, 0LL, size).ind;
	}
};





lli N,
	h[MAX_SIZE],
	c[MAX_SIZE];
segtree st;
lli ans;

void solve();
lli get_min_cost(lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
	cin >> N;
	for (int i = 0; i < (int)N; ++i)
		cin >> h[i];
	for (int i = 0; i < (int)N; ++i)
		cin >> c[i];
	
	st.init(N, h);
	
	ans = get_min_cost(0LL, N);
	cout << ans << '\n';
	return;
}

lli get_min_cost(lli l, lli r) {
	if (!(l < r))
		return 0LL;
	
	lli ind_of_max = st.get_ind_of_max(l, r);
	
	return c[ind_of_max] + min(
		get_min_cost(l, ind_of_max),
		get_min_cost(ind_of_max + 1LL, r)
	);
}
