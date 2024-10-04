// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE],
    pref[MAX_SIZE]; // pref[i] = sum( A on [0, i) )
plli inds[3] = {{-1LL, -1LL}, {-1LL, -1LL}, {-1LL, -1LL}};

void solve();
lli f(lli, lli);
bool comp(const plli&, const plli&);

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
    
    for (int i = 0; i <= (int)N; ++i) {
        lli ind = f(pref[i], 3LL);
        if (inds[ind].first == -1LL)
            inds[ind].first = (lli)i;
    }
    
    for (int i = (int)N; i >= 0; --i) {
        lli ind = f(pref[i], 3LL);
        if (inds[ind].second == -1LL)
            inds[ind].second = (lli)i;
    }
    
    sort(inds, inds + 3, comp);

    if (inds[0].first != -1LL and inds[0].first != inds[0].second)
        cout << (inds[0].first + 1LL) << ' ' << inds[0].second << '\n';
    else
        cout << "-1\n";

    return;
}

lli f(lli num, lli d) {
    if (num < 0LL)
        return (d + num % d) % d;
    return num % d;
}

bool comp(const plli &p1, const plli &p2) {
    if (p1.second - p1.first == p2.second - p2.first)
        return p1.first < p2.first;
    return p1.second - p1.first > p2.second - p2.first;
}
