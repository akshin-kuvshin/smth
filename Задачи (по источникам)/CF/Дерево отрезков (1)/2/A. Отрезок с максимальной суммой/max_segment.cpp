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
    class Node {
    public:
        lli pref;
        lli suf;
        lli seg;
        lli sum;
        
        Node() {
        	*this = Node(0LL, 0LL, 0LL, 0LL);
        	return;
		}
        
        Node(lli _pref, lli _suf, lli _seg, lli _sum) {
        	pref = max(_pref, 0LL); // пишем std::max, т.к. всегда можно выбрать пустой отрезок (префикс/суффикс), сумма на котором равна нулю.
        	suf = max(_suf, 0LL);
        	seg = max(_seg, 0LL);
        	sum = _sum;
        	return;
		}
    };
    
    Node combine(Node n1, Node n2) {
    	Node result;
    	result.pref = max(n1.pref, n1.sum + n2.pref);
    	result.suf = max(n1.suf + n2.sum, n2.suf);
    	result.seg = max(max(n1.seg, n2.seg), n1.suf + n2.pref);
    	result.sum = n1.sum + n2.sum;
    	return result;
	}

    Node tree[MAX_SIZE + 5LL];
    lli size;

public:
    void init(lli original_size) {
        size = 1LL;
        while (size < original_size)
            size <<= 1;
        return;
    }
    
    void set(lli i, lli value, lli x, lli lx, lli rx) {
    	if (rx - lx == 1LL) {
    		tree[x] = Node(value, value, value, value);
    		return;
		}
		
		lli mid = (lx + rx) / 2LL;
		if (i < mid)
			set(i, value, 2LL * x + 1LL, lx, mid);
		else
			set(i, value, 2LL * x + 2LL, mid, rx);
		tree[x] = combine(tree[2LL * x + 1LL], tree[2LL * x + 2LL]);
		return;
	}

    void set(lli i, lli value) {
    	set(i, value, 0LL, 0LL, size);
    	return;
	}
	
	lli max_segment() {
		return tree[0].seg;
	}
};

lli N,
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
    st.init(N);
    for (int i = 0; i < (int)N; ++i) {
    	lli value;
    	cin >> value;
    	st.set((lli)i, value);
	}
	
	cout << st.max_segment() << '\n';
	while (M--) {
		lli i,
			value;
		cin >> i >> value;
		st.set(i, value);
		cout << st.max_segment() << '\n';
	}
    
    return;
}
