// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define vertex  first
#define length  second
#define INF     (lli)1e18

const lli MAX_SIZE = (lli)5e2 + 5LL,
          EMPTY_TRUCK_WEIGHT = (lli)3e6,
          ONE_CUP_WEIGHT = 100LL,
          MIN_ANS = 0LL,
          MAX_ANS = (lli)1e7,
          MAX_TIME = 1440LL;

class Rib {
public:
    lli to;
    lli cost;
    lli max_weight;

    Rib(lli __to, lli __cost, lli __max_weight) {
        to = __to;
        cost = __cost;
        max_weight = __max_weight;
        return;
    }
};

class Compare {
public:
    bool operator ()(const plli &p1, const plli &p2) const {
        if (p1.length == p2.length)
            return p1.vertex < p2.vertex;
        return p1.length < p2.length;
    }
};

lli N;
vector<Rib> G[MAX_SIZE];
lli M,
    _u,
    _v,
    _cost,
    _max_weight;
lli answer;

set<plli, Compare> q;
lli d[MAX_SIZE];
bool used[MAX_SIZE];

void input();
void solve();
lli bs();
bool check_ans(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solve();
    
    return 0;
}

void input() {
    cin >> N >> M;
    while (M--) {
        cin >> _u >> _v >> _cost >> _max_weight;
        G[_u].pb(Rib(_v, _cost, _max_weight));
        G[_v].pb(Rib(_u, _cost, _max_weight));
    }
    return;
}

void solve() {
    answer = bs();
    cout << answer << '\n';
    return;
}

lli bs() {
    lli l = MIN_ANS,
        r = MAX_ANS + 1LL;
    while (l + 1LL < r) {
        lli mid = (l + r) >> 1;
        if (check_ans(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}

bool check_ans(lli cups_amount) {
    q.clear();
    fill(d + 1LL, d + 1LL + N, INF);
    fill(used + 1LL, used + 1LL + N, false);

    lli weight = EMPTY_TRUCK_WEIGHT + ONE_CUP_WEIGHT * cups_amount;

    lli start = 1LL,
        finish = N;
    d[start] = 0LL;
    for (int i = 1; i <= (int)N; ++i)
        q.insert(mp(i, d[i]));
    
    while (!q.empty()) {
        plli current = *(q.begin());
        q.erase(q.begin());

        if (current.length == INF)
            break;
        
        used[current.vertex] = true;
        if (current.vertex == finish)
            break;
        
        for (Rib ns : G[current.vertex]) {
            if (used[ns.to])
                continue;
            if (weight > ns.max_weight)
                continue;
            
            lli new_length = current.length + ns.cost;
            if (new_length < d[ns.to]) {
                q.erase(mp(ns.to, d[ns.to]));
                d[ns.to] = new_length;
                q.insert(mp(ns.to, d[ns.to]));
            }
        }
    }

    return (d[finish] <= MAX_TIME);
}
