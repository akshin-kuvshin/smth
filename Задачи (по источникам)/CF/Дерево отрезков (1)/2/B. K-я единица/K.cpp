// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

const lli MAX_SIZE = (1LL << 20);



class segtree {
private:
	lli tree[MAX_SIZE + 5LL];
	lli size;

public:
	void init(lli original_size) {
		size = 1LL;
		while (size < original_size)
			size <<= 1;
		return;
	}
	
	void build(lli *arr, lli sz, lli x, lli lx, lli rx) {
		if (rx - lx == 1LL) {
			if (lx < sz)
				tree[x] = arr[lx];
			return;
		}
		
		lli mid = (lx + rx) / 2LL;
		build(arr, sz, 2LL * x + 1LL, lx, mid);
		build(arr, sz, 2LL * x + 2LL, mid, rx);
		tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
		return;
	}
	
	void build(lli *arr, lli sz) {
		init(sz);
		build(arr, sz, 0LL, 0LL, size);
		return;
	}
	
	void change(lli i, lli x, lli lx, lli rx) {
		if (rx - lx == 1LL) {
			tree[x] = (tree[x] ? 0LL : 1LL);
			return;
		}
		
		lli mid = (lx + rx) / 2LL;
		if (i < mid)
			change(i, 2LL * x + 1LL, lx, mid);
		else
			change(i, 2LL * x + 2LL, mid, rx);
		tree[x] = tree[2LL * x + 1LL] + tree[2LL * x + 2LL];
		return;
	}
	
	void change(lli i) {
		change(i, 0LL, 0LL, size);
		return;
	}
	
	lli find(lli k, lli x, lli lx, lli rx) {
		if (rx - lx == 1LL)
			return lx;
		
		lli mid = (lx + rx) / 2LL,
			s = tree[2LL * x + 1LL];
		
		if (s >= k)
			return find(k, 2LL * x + 1LL, lx, mid);
		return find(k - s, 2LL * x + 2LL, mid, rx);
	}
	
	lli find(lli k) {
		return find(k, 0LL, 0LL, size);
	}
};




lli N,
	A[MAX_SIZE + 5LL],
	M;
segtree st;



void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
    	cin >> A[i];
    st.build(A, N);
    
    while (M--) {
    	lli op,
    		param;
    	cin >> op >> param;
    	
    	if (op == 1LL)
    		st.change(param);
    	else { // op == 2LL
    		++param;
    		cout << st.find(param) << '\n';
    	}
	}
    
    return;
}
