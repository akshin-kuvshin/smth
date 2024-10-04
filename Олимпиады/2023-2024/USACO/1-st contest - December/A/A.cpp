// author: Danila "akshin_" Axyonov

#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define weight              first
#define amount              second

#define _iterator           set<plli>::iterator

const lli MAX_SIZE = (lli)2e5 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N;
plli tmp;
set<plli> S;
lli M,
    K;
lli towers,
    cows;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < (int)N; ++i) {
        cin >> tmp.weight >> tmp.amount;
        S.insert(tmp);
    }
    
    while (!S.empty() and towers < M) {
        vector<plli> w;
        w.pb(*S.begin());
        
        _iterator it;
        while ((it = S.lower_bound(mp(w.back().weight + K, 0LL))) != S.end())
            w.pb(*it);
        
        lli towers_amount = INF;
        for (plli p : w)
            towers_amount = min(towers_amount, p.amount);
        towers_amount = min(towers_amount, M - towers);

        for (plli p : w) {
            it = S.lower_bound(p);
            S.erase(it);
            
            p.amount -= towers_amount;
            if (p.amount > 0LL)
                S.insert(p);
        }

        towers += towers_amount;
        cows += towers_amount * (lli)w.size();
    }

    cout << cows << '\n';
    return;
}
