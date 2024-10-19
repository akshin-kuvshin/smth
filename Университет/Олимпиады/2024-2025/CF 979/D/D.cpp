// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define L                   'L'
#define R                   'R'

const lli MAX_SIZE = (lli)2e5 + 5LL;

lli T;
lli N,
    Q;
vector<lli> P,
            pref_P,
            pref_sorted_P;
vector<char> S;
set<pair<int, int>> available_breaks,
                    current_breaks;

void solve();
bool contains(const set<pair<int, int>>&, pair<int, int>);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pref_sorted_P.resize(MAX_SIZE + 1LL);
    for (int i = 0; i < (int)MAX_SIZE; ++i) // sorted_P = [1, 2, 3, ..., N]
        pref_sorted_P[i + 1] = pref_sorted_P[i] + (lli)i + 1LL;
    
    cin >> T;
    while (T--)
        solve();
    
    return 0;
}

void solve() {
    available_breaks.clear();
    current_breaks.clear();

    cin >> N >> Q;
    P.resize(N);
    pref_P.assign(N + 1LL, 0LL);
    S.resize(N);
    for (int i = 0; i < (int)N; ++i)
        cin >> P[i];
    for (int i = 0; i < (int)N; ++i)
        cin >> S[i];
    
    for (int i = 0; i < (int)N; ++i)
        pref_P[i + 1] = pref_P[i] + P[i];
    
    for (int i = 0; i < (int)N; ++i)
        if (pref_P[i + 1] == pref_sorted_P[i + 1])
            available_breaks.insert(mp(i, i + 1));
    
    for (int i = 0; i + 1 < (int)N; ++i)
        if (S[i] == L and S[i + 1] == R) { // have a break {i, i + 1}
            if (contains(available_breaks, mp(i, i + 1))) continue;
            current_breaks.insert(mp(i, i + 1));
        }
    


    while (Q--) { // обрабатываем запросы
        int i;
        cin >> i;
        --i;
        S[i] = (S[i] == L ? R : L);

        // checking for {i - 1, i}
        if (S[i - 1] == L and S[i] == R) {
            if (not contains(available_breaks, mp(i - 1, i)))
                current_breaks.insert(mp(i - 1, i));
        } else current_breaks.erase(mp(i - 1, i));

        // checking for {i, i + 1}
        if (S[i] == L and S[i + 1] == R) {
            if (not contains(available_breaks, mp(i, i + 1)))
                current_breaks.insert(mp(i, i + 1));
        } else current_breaks.erase(mp(i, i + 1));

        cout << (current_breaks.empty() ? "YES\n" : "NO\n");
    }


    
    return;
}

bool contains(const set<pair<int, int>> &SS, pair<int, int> pp) {
    auto it = SS.lower_bound(pp);
    if (it != SS.end() and *it == pp)
        return true;
    return false;
}
