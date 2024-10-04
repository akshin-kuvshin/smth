// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#define pb(_elem)			push_back(_elem)
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;
#define mp(_first, _second)	make_pair(_first, _second)
#define to					first
#define cost				second
#define vertex				first
#define length				second

const lli MAX_SIZE = (lli)1e5 + 5LL,
		  INF = (lli)1e9 + 1LL,
		  ROOT = -1LL;

lli N;
vector<plli> G[MAX_SIZE];
lli M,
	u,
	v,
	w;
lli d;
lli _minmax;
lli way[MAX_SIZE],
	top;

lli bs();
bool f(lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M >> d;
	while (M--) {
		cin >> u >> v >> w;
		G[u].pb(mp(v, w));
	}
	
	_minmax = bs();
	if (_minmax == INF) {
		cout << "-1\n";
		return 0;
	}
	
	queue<plli> q;
	bool used[MAX_SIZE];
	fill(used + 1LL, used + 1LL + N, false);
	lli p[MAX_SIZE];
	
	q.push(mp(1LL, 0LL));
	used[1] = true;
	p[1] = ROOT;
	while (!q.empty()) {
		plli cur = q.front();
		q.pop();
		
		if (cur.length > d)
			continue;
		if (cur.vertex == N)
			break;
		
		for (plli ns : G[cur.vertex]) {
			if (used[ns.to])
				continue;
			if (ns.cost > _minmax)
				continue;
			
			q.push(mp(ns.to, cur.length + 1LL));
			used[ns.to] = true;
			p[ns.to] = cur.vertex;
		}
	}
	
	for (lli x = N; x != ROOT; x = p[x])
		way[top++] = x;
	
	cout << (top - 1LL) << '\n';
	for (int i = (int)top - 1; i >= 0; --i)
		cout << way[i] << ' ';
	cout << '\n';
	return 0;
}

lli bs() {
	lli l = -1LL,
		r = INF;
	while (l + 1LL < r) {
		lli mid = (l + r) >> 1;
		if (f(mid))
			r = mid;
		else
			l = mid;
	}
	return r;
}

bool f(lli x) {
	queue<plli> q;
	bool used[MAX_SIZE];
	fill(used + 1LL, used + 1LL + N, false);
	
	q.push(mp(1LL, 0LL));
	used[1] = true;
	while (!q.empty()) {
		plli cur = q.front();
		q.pop();
		
		if (cur.length > d)
			continue;
		if (cur.vertex == N)
			return true;
		
		for (plli ns : G[cur.vertex]) {
			if (used[ns.to])
				continue;
			if (ns.cost > x)
				continue;
			
			q.push(mp(ns.to, cur.length + 1LL));
			used[ns.to] = true;
		}
	}
	
	return false;
}
