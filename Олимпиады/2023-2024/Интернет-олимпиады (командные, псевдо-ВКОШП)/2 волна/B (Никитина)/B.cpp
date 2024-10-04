#include <iostream>
#include <vector>
#define ll long long
using namespace std;
 
ll n, s1, cur, ans = 1e16;
vector<ll> a;
vector<ll> p;
 
int main() {
    cin >> n;
    a.resize(n + 1);
    p.resize(n + 1);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s1 += (i - 1) * a[i];
        p[i] = p[i - 1] + a[i];
    }
    cur = s1;
    for (int i = 1; i <= n; i++) {
        cur += 2 * p[i] - p[n];
        //cout << cur << endl;
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
