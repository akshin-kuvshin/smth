#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e5 + 5LL,
		  VERY_MAX_DAY = (lli)1e9 + 1LL;

struct Node {
	lli d;
	lli w;
	double waste;
};

lli N;
Node A[MAX_SIZE];
double r;
lli M,
	q[MAX_SIZE];

void solve();
bool comp(const Node&, const Node&);
lli bs(lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
	cin >> N >> M;
	cin >> r;
	for (int i = 1; i <= (int)N; ++i)
		cin >> A[i].d >> A[i].w;
	for (int k = 0; k < (int)M; ++k)
		cin >> q[k];
	
	A[0] = {0LL, 0LL, 0.0};
	sort(A + 1, A + 1 + (int)N, comp);
	for (int i = 1; i <= (int)N; ++i)
		A[i].waste = A[i - 1].waste * pow(1.0 - r, A[i].d - A[i - 1].d) + (double)A[i].w * r;
	A[N + 1LL] = {VERY_MAX_DAY, 0LL, 0.0};
	A[N + 1LL].waste = A[N].waste * pow(1.0 - r, A[N + 1LL].d - A[N].d);
	
	for (int k = 0; k < (int)M; ++k) {
		lli cur = q[k];
		lli ind = bs(cur);
		// A[ind].d <= cur
		
		if (A[ind].d == cur)
			cout << fixed << setprecision(20) << A[ind].waste << '\n';
		else {
			double result = A[ind].waste * pow(1.0 - r, cur - A[ind].d);
			cout << fixed << setprecision(20) << result << '\n';
		}
	}
	
	return;
}

bool comp(const Node &n1, const Node &n2) {
	return n1.d < n2.d;
}

lli bs(lli cur) {
	lli l = 0LL,		// A[l].d <= cur_d
		r = N + 1LL;	// cur_d < A[r].d
	while (l + 1LL < r) {
		lli mid = (l + r) >> 1;
		if (A[mid].d <= cur)
			l = mid;
		else
			r = mid;
	}
	return l;
}
