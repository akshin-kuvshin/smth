// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e5 + 5LL,
		  INF = (lli)1e18 + 1LL;

class Medal {
public:
	lli a;
	lli b;
	lli c;
};

lli N,
	S;
Medal M[MAX_SIZE];
lli ans;

lli bs();
bool f(lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> S;
	for (int i = 0; i < (int)N; ++i)
		cin >> M[i].a >> M[i].b >> M[i].c;
	
	ans = bs();
	cout << ans << '\n';
	return 0;
}

lli bs() {
	lli l = 1LL,
		r = MAX_SIZE;
	
	while (l + 1LL < r) {
		lli mid = (l + r) >> 1;
		if (f(mid))
			l = mid;
		else
			r = mid;
	}
	
	return l;
}

bool f(lli x) {
	lli gold = INF,
		silver = INF,
		bronze = INF;
	
	for (int i = 0; i < (int)N; ++i) {
		if (M[i].b < x) continue;
		
		if (M[i].c == 1LL and M[i].a < gold)
			gold = M[i].a;
		else if (M[i].c == 2LL and M[i].a < silver)
			silver = M[i].a;
		else if (M[i].c == 3LL and M[i].a < bronze)
			bronze = M[i].a;
	}
	
	return (gold + silver + bronze <= S);
}
