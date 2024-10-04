// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N,
    A[MAX_SIZE];
lli pref[MAX_SIZE]; // pref[i] = sum( A on [0, i) )
plli pref_min[MAX_SIZE]; // pref_min[i] = min( A on [0, i] )
lli max_sum = -INF;
plli max_ind;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    pref[0] = 0LL;
    for (int i = 0; i < (int)N; ++i)
        pref[i + 1] = pref[i] + A[i];
    
    pref_min[0] = {pref[0], 0LL};
    for (int i = 1; i <= (int)N; ++i)
        if (pref[i] <= pref_min[i - 1].first)
            pref_min[i] = make_pair(pref[i], (lli)i);
        else
            pref_min[i] = pref_min[i - 1];
    
    for (int i = 1; i <= (int)N; ++i) {
        lli new_sum = pref[i] - pref_min[i - 1].first;
        lli a = pref_min[i - 1].second,
            b = (lli)i;
        
        if (new_sum > max_sum) {
            max_sum = new_sum;
            max_ind = make_pair(a, b);
        }
    }
    
    cout << (max_ind.first + 1LL) << '\n' << max_ind.second << '\n';
    
    return;
}
