// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numbers>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define x                   first
#define y                   second

const long double PI = numbers::pi_v<long double>;

void solve();
plli make_vector(plli a, plli b);
lli get_cr_pr(plli u, plli v); // [u, v]
lli get_sc_pr(plli u, plli v); // (u, v)
vector<plli> get_clockwise_convex_hull(vector<plli> a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n,
        l;
    cin >> n >> l;
    vector<plli> a(n);
    for (plli& ai : a)
        cin >> ai.x >> ai.y;
    
    vector<plli> convex_hull = get_clockwise_convex_hull(a);
    
    convex_hull.pb(convex_hull.front());
    long double length = 0.l;
    for (int i = 0; i + 1 < (int)convex_hull.size(); ++i) {
        plli u = make_vector(convex_hull[i], convex_hull[i + 1]);
        length += hypot(1.l * u.x, 1.l * u.y);
    }
    
    convex_hull.pb(*(convex_hull.begin() + 1));
    for (int i = 1; i + 1 < (int)convex_hull.size(); ++i) {
        plli u = make_vector(convex_hull[i], convex_hull[i - 1]),
             v = make_vector(convex_hull[i], convex_hull[i + 1]);
        lli cr_pr = get_cr_pr(u, v),
            sc_pr = get_sc_pr(u, v);
        long double angle1 = atan2(1.l * cr_pr, 1.l * sc_pr);
        long double angle = PI - angle1;
        length += l * angle;
    }
    
    cout << llround(length) << '\n';
    return;
}

plli make_vector(plli a, plli b) {
    return mp(b.x - a.x, b.y - a.y);
}

lli get_cr_pr(plli u, plli v) {
    return u.x * v.y - v.x * u.y;
}

lli get_sc_pr(plli u, plli v) {
    return u.x * v.x + u.y * v.y;
}

vector<plli> get_clockwise_convex_hull(vector<plli> a) {
    vector<plli> up,
                 down;

    sort(a.begin(), a.end());
    for (plli ai : a) {
        while ((int)up.size() >= 2) {
            plli u = make_vector(*(up.end() - 2), *(up.end() - 1)),
                 v = make_vector(*(up.end() - 2), ai);
            if (get_cr_pr(u, v) < 0LL)
                break;
            up.pop_back();
        }
        up.pb(ai);
        
        while ((int)down.size() >= 2) {
            plli u = make_vector(*(down.end() - 2), *(down.end() - 1)),
                 v = make_vector(*(down.end() - 2), ai);
            if (get_cr_pr(u, v) > 0LL)
                break;
            down.pop_back();
        }
        down.pb(ai);
    }
    
    // result will be in clockwise order
    vector<plli> convex_hull = up;
    for (int i = (int)down.size() - 2; i > 0; --i)
        convex_hull.pb(down[i]);
    
    return convex_hull;
}

