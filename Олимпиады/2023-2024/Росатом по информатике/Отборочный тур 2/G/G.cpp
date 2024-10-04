// author: Danila "akshin_" Axyonov

// Это пиздец полный... Я не додумался до решения на фулл и решил просто расписать две несложные группы тестов,
// а это залупское решение зашло на фулл... Я не знаю, что мне думать...

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define type                first
#define vertex              second

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N;
vector<lli> G[MAX_SIZE];
lli p[MAX_SIZE];
lli M,
    u,
    v;
lli Q,
    type,
    vertex;

void solve();
void star_solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M >> Q;
    for (int _ = 0; _ < (int)M; ++_) {
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    
    // Вторая группа тестов
    if (M == N - 1LL and (lli)G[0].size() == M) {
        star_solve();
        return;
    }
    
    while (Q--) {
        cin >> type >> vertex;
        --vertex;

        if (type == 1LL) {
            ++p[vertex];
            for (lli ns : G[vertex])
                ++p[ns];
        } else // type == 2LL
            cout << p[vertex] << '\n';
    }

    return;
}

void star_solve() {
    lli p0 = 0LL;
    while (Q--) {
        cin >> type >> vertex;
        --vertex;

        if (type == 1LL) {
            if (vertex == 0LL)
                ++p0;
            else {
                ++p[vertex];
                ++p[0];
            }
        } else // type == 2LL
            cout << (p[vertex] + p0) << '\n';
    }

    return;
}
