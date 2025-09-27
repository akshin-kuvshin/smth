// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define x                   first
#define y                   second

void solve();
vector<plli> get_convex_hull(vector<plli> a);
lli get_cr_pr(plli a, plli b, plli c); // [ab, ac]
bool cmp(plli p1, plli p2);

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
    for (plli& ai : a)
        cin >> ai.x >> ai.y;
    sort(a.begin(), a.end(), cmp);
    
    lli m;
    cin >> m;
    vector<plli> b(m);
    for (plli& bi : b)
        cin >> bi.x >> bi.y;
    
    vector<plli> c = a;
    copy(b.begin(), b.end(), back_inserter(c));
    
    vector<plli> convex_hull = get_convex_hull(c);
    sort(convex_hull.begin(), convex_hull.end(), cmp);
    cout << (convex_hull == a ? "YES" : "NO") << '\n';
    return;
}

vector<plli> get_convex_hull(vector<plli> a) {
    sort(a.begin(), a.end(), cmp);
    vector<plli> up,
                 down;
    for (int i = 0; i < (int)a.size(); ++i) {
        while ((int)up.size() >= 2 and get_cr_pr(*(up.end() - 2), *(up.end() - 1), a[i]) > 0)
            up.pop_back();
        up.pb(a[i]);
        
        while ((int)down.size() >= 2 and get_cr_pr(*(down.end() - 2), *(down.end() - 1), a[i]) < 0)
            down.pop_back();
        down.pb(a[i]);
    }
    vector<plli> convex_hull = up;
    copy(down.begin() + 1, down.end() - 1, back_inserter(convex_hull));
    return convex_hull;
}

lli get_cr_pr(plli a, plli b, plli c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cmp(plli p1, plli p2) {
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

