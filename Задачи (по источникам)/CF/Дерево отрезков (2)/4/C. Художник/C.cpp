// author: Danila "akshin_" Axyonov

// Итак, я подправил прошлую версию, и вот то, что мои глаза и мозг могут назвать "приятным" и "структурированным" кодом.
// :)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define WHITE				0LL
#define BLACK				1LL

#define NO_EQ				-1LL

#define left				(2LL * x + 1LL)
#define right				(2LL * x + 2LL)

const lli N = (lli)5e5,
          N2 = (lli)1e6 + 1LL;






class Node {
public:
	lli front;
	lli back;
	lli segs;
	lli black_len;
	
	Node() {
		front = WHITE;
		back = WHITE;
		segs = 1LL;
		black_len = 0LL;
		return;
	}
	
	Node(lli __front, lli __back, lli __segs, lli __black_len) {
		front = __front;
		back = __back;
		segs = __segs;
		black_len = __black_len;
		return;
	}
};

Node combine(const Node &n1, const Node &n2) {
    Node result;
    result.front = n1.front;
    result.back = n2.back;
    result.segs = n1.segs + n2.segs;
    if (n1.back == n2.front)
        --result.segs;
    result.black_len = n1.black_len + n2.black_len;
    return result;
}






class segtree {
private:
	vector<Node> tree;
	vector<lli> op;
	lli size;
	
	void propagate(lli x, lli lx, lli rx) {
        lli len2 = (rx - lx) >> 1;

		op[left] = op[x];
		tree[left] = Node(op[left], op[left], 1LL, ((op[left] == WHITE) ? 0LL : len2));
		
		op[right] = op[x];
		tree[right] = Node(op[right], op[right], 1LL, ((op[right] == WHITE) ? 0LL : len2));
		
		op[x] = NO_EQ;
		tree[x] = combine(tree[left], tree[right]);
		
		return;
	}
	
	void set(lli l, lli r, lli color, lli x, lli lx, lli rx) {
		if (rx <= l or r <= lx)
			return;
		if (l <= lx and rx <= r) {
			op[x] = color;
			tree[x] = Node(op[x], op[x], 1LL, ((op[x] == WHITE) ? 0LL : (rx - lx)));
			return;
		}
		
		if (op[x] != NO_EQ)
			propagate(x, lx, rx);
		
		lli mid = (lx + rx) >> 1;
		set(l, r, color, left, lx, mid);
		set(l, r, color, right, mid, rx);
		tree[x] = combine(tree[left], tree[right]);
		return;
	}

public:
	void init(lli original_size) {
		size = 1LL;
		while (size < original_size)
			size <<= 1;
		tree.assign(2LL * size - 1LL, Node());
        op.assign(2LL * size - 1LL, NO_EQ);
		return;
	}
	
	void set(lli l, lli r, lli color) {
		set(l, r, color, 0LL, 0LL, size);
		return;
	}
	
	plli get_ans() { return mp(tree[0].segs >> 1, tree[0].black_len); }
};






segtree st;
lli Q;
char cmd;
lli x,
	l;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    st.init(N2);
    
    cin >> Q;
    while (Q--) {
    	cin >> cmd >> x >> l;
    	x += N;
    	st.set(x, x + l, ((cmd == 'W') ? WHITE : BLACK));
		plli ans = st.get_ans();
		cout << ans.first << ' ' << ans.second << '\n';
	}
    
    return;
}
