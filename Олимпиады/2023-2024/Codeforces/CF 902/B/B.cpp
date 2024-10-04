// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define cost    first
#define amount  second

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli Q;
lli N,
    p;
plli A[MAX_SIZE];
lli cnt,
    d;
lli answer;

void solve();
bool comp(const plli&, const plli&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cnt = d = answer = 0LL;

    cin >> N >> p;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i].amount;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i].cost;
    sort(A, A + N, comp);
    
    for (int i = 0; i < (int)N; ++i) {
        if (!d) {
            answer += p;
            ++cnt;
            ++d;
        }
        
        --d;

        lli best_cost = min(A[i].cost, p),
            required = min(A[i].amount, N - cnt);
        answer += best_cost * required;
        cnt += required;
        d += required;
    }
    
    cout << answer << '\n';
    return;
}

bool comp(const plli &p1, const plli &p2) {
    if (p1.cost == p2.cost)
        return p1.amount > p2.amount;
    return p1.cost < p2.cost;
}
