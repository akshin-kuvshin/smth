// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;
#define h           first
#define c           second
#define pb(elem_)   push_back(elem_)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli ans = 0LL;

    lli n,
        m;
    cin >> n >> m;

    multiset<lli> swords;
    while (n--) {
        lli x;
        cin >> x;
        swords.insert(x);
    }

    vector<plli> monsters(m);
    for (int i = 0; i < (int)m; ++i)
        cin >> monsters[i].h;
    for (int i = 0; i < (int)m; ++i)
        cin >> monsters[i].c;
    
    vector<plli> good;
    vector<lli> bad;
    for (plli monster : monsters) {
        if (monster.c)
            good.pb(monster);
        else // monster.c == 0LL
            bad.pb(monster.h);
    }
    
    sort(good.begin(), good.end());
    for (plli monster : good) {
        auto it = swords.lower_bound(monster.h);
        if (it == swords.end())
            continue;
        ++ans;
        lli new_x = max(*it, monster.c);
        swords.erase(it);
        swords.insert(new_x);
    }

    sort(bad.begin(), bad.end());
    for (lli health : bad) {
        auto it = swords.lower_bound(health);
        if (it == swords.end())
            continue;
        ++ans;
        swords.erase(it);
    }

    cout << ans << '\n';
}
