// author: Danila "akshin_" Axyonov
// with editorial

/*
Заметим, что хорошая пара (p, q) получается в 2-ух случаях:
1) p - не лист; q - лист. Тогда Анор выигрывает автоматически;
2) p - вершина, не имеющая соседей-листов; предпоследняя вершина гусеницы имеет соседа листа.
   Тогда Анор выигрывает вторым ходом.

В переменной leafes считаем кол-во листьев в дереве. Тогда существует (n - leafes) * leafes пар,
подходящих под случай 1.

Переменная p-good - кол-во вершин, подходящих в качестве вершины p из случая 2;
           q-good - соответственно, кол-во вершин, подходящий в качестве вершины q.
Для каждой вершины считаем число q - кол-во соседей, не являющихся листьями. Тогда для любой вершины p
текущая вершина даст (q - 1) потенциальных вершин q (единицу отнимаем, потому что одна из них будет лежать
на простом пути p<->q). То есть каждую вершину мы представляем, как предпоследнюю в гусенице, а затем
считаем число вершин, подходяших в качестве последней, которые бы после хода Норы попадали в текущую.
*/

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)
#define deg(_index)         (lli)G[_index].size()

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
    lli n;
    cin >> n;
    vector<vector<lli>> G(n);
    for (int _ = 0; _ + 1 < (int)n; ++_) {
        lli u,
            v;
        cin >> u >> v;
        --u; --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    lli leafes = 0LL,
        p_good = 0LL,
        q_good = 0LL;
    for (int i = 0; i < (int)n; ++i) {
        if (deg(i) == 1LL) {
            ++leafes;
            continue;
        }
        lli q = 0LL;
        for (auto nb : G[i])
            if (deg(nb) > 1LL)
                ++q;
        if (deg(i) == q)
            ++p_good;
        else // there is at least one leaf-neighbour
            q_good += q - 1LL;
    }

    lli ans = leafes * (n - leafes) + p_good * q_good;
    cout << ans << '\n';    
    return;
}
