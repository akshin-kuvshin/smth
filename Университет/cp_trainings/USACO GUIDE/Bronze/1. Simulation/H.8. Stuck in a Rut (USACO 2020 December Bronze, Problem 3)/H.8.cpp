// author: Danila "akshin_" Axyonov
// Буду честен: прежде чем получить вердикт "Submitted", я подглядел в решение другого человека.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    size_t n;
    cin >> n;
    vector<plli> north,
                 east;
    vector<lli> xs; // нужен для того, чтобы помнить исходный порядок коров.
    unordered_map<lli, lli> ans;
    for (size_t _ = 0ULL; _ < n; ++_) {
        char dir;
        lli x, y;
        cin >> dir >> x >> y;
        if (dir == 'N') north.pb(mp(x, y));
        else /* dir == 'E' */ east.pb(mp(x, y));
        xs.pb(x);
        ans[x] = 0LL;
    }
    
    // тех, кто идёт вверх, сортируем по x-координате,
    // тех, кто идёт вправо - по y-координате.
    sort(north.begin(), north.end());
    sort(east.begin(), east.end(), [](const plli &p1, const plli &p2) {
        return p1.second < p2.second;
    });

    for (auto [xn, yn] : north) { // перебираем всех "северных" коров слева направо.
        for (auto [xe, ye] : east) { // для каждой "северной" коровы перебираем всех "восточных" снизу вверх.
            if (ans[xe]) continue; // если "восточная" корова уже врезалась в какую-то "северную" корову из числа тех, кого мы уже перебрали, то эту "восточную" корову не рассматриваем.
            if (xn < xe or yn > ye) continue; // если наши коровы даже не могут столкнуться (определяем по координатам), то данную пару не рассматриваем и идём к следующей "восточной" корове.
            // now xn > xe, yn < ye
            lli dn = ye - yn, // расстояние, которая пройдёт "северная" корова до места потенциального пересечения.
                de = xn - xe; // аналогично для "восточной" коровы.
            if (dn < de) // если "северная" корова окажется на месте пересечения раньше, то она выживает, а "восточная" корова останавливается.
                ans[xe] = de;
            else if (dn > de) { // если же останавливается "северная" корова, то переходим к следующей "северной" корове.
                ans[xn] = dn;
                break;
            }
        }
    }
    
    for (auto x : xs)
        if (ans[x])
            cout << ans[x] << '\n';
        else // ans[x] == 0LL
            cout << "Infinity\n";
    return;
}
