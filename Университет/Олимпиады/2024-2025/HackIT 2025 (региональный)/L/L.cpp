// author: Danila "akshin_" Axyonov

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define x   first
#define y   second

void solve();
double bs(lli n, const vector<plli>& a);
bool f(lli n, const vector<plli>& a, double h);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<plli> a(n);
    for (plli& p : a)
        cin >> p.x >> p.y;
	
	double ans = bs(n, a);
	cout << fixed << setprecision(20) << ans << '\n';
	return;
}

double bs(lli n, const vector<plli>& a) {
    double l = 0.,
           r = 1e18;
    for (int _ = 0; _ < 100; ++_) {
        double m = (l + r) * .5;
        if (f(n, a, m))
            r = m;
        else
            l = m;
    }
    return r;
}

bool f(lli n, const vector<plli>& a, double h) {
    vector<vector<lli>> G(n);
    for (int i = 0; i < (int)n; ++i)
        for (int j = i + 1; j < (int)n; ++j)
            if ((double)((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y)) <= h * h) {
                G[i].push_back((lli)j);
                G[j].push_back((lli)i);
            }
    
    queue<lli> q;
    vector<bool> used(n);
    
    q.push(0LL);
    used[0] = true;
    while (not q.empty()) {
        lli cur = q.front();
        q.pop();
        
        for (lli nb : G[cur]) {
            if (used[nb])
                continue;
            q.push(nb);
            used[nb] = true;
        }
    }
    
    bool all = true;
    for (bool used_i : used)
        all = all and used_i;
    return all;
}
