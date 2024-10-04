#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

#define _max        first
#define _min        first
#define to          second

const lli MAX_SIZE = (lli)2e5 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N;
vector<lli> G[MAX_SIZE];
plli max_depth[MAX_SIZE],
     min_depth[MAX_SIZE];
lli ans;

void count_depths(lli v) {
    max_depth[v] = make_pair(0LL, -1LL);
    min_depth[v] = make_pair(INF, -1LL);

    for (lli ns : G[v])
        count_depths(ns);

    for (int i = 0; i < (int)G[v].size(); ++i) {
        lli ns = G[v][i];
        if (max_depth[ns].to == -1LL)
            max_depth[v] = max(max_depth[v], make_pair(1LL, ns));
        else
            max_depth[v] = max(max_depth[v], make_pair(max_depth[ns]._max + 1LL, ns));
    }

    for (int i = 0; i < (int)G[v].size(); ++i) {
        lli ns = G[v][i];
        if (min_depth[ns].to == -1LL)
            min_depth[v] = min(min_depth[v], make_pair(1LL, ns));
        else
            min_depth[v] = min(min_depth[v], make_pair(min_depth[ns]._min + 1LL, ns));
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (lli i = 2LL; i <= N; ++i) {
        lli prim;
        cin >> prim;
        G[prim].push_back(i);
    }

    count_depths(1);

    lli blue = 1LL,
        red = 1LL;
    ans = 1LL;
    while (true) {
        blue = max_depth[blue].to;
        // cerr << "move blue to " << blue << '\n';
        if (G[blue].empty())
            break;

        red = min_depth[red].to;
        // cerr << "move red to " << red << '\n';
        if (G[red].empty()) {
            red = blue;
            ++ans;
        }
    }

    cout << ans << '\n';
    return 0;
}
