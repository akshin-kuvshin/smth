// author: Danila "akshin_" Axyonov

// ЛЕТСГОУ НАХУЙ!!! ПАПОЧКА ЗАРЕШАЛ!!! Я УМНЕЙШИЙ ИЗ КИТАЙЦЕВ!!!
// Поясняю: я пишу задачу, сдаю её в 1:56:47 (всего контест идёт 2 часа) и получаю TL на тесте 9.
// Моментально понимаю, где он происходит; менее, чем за две минуты я своими дрожащими руками
// делаю фикс, отправляю задачу в 1:58:33 (менее полуторы минуты до конца контеста), получаю AC
// и ору на всю квартиру, что папочка зарешал, что я "умнейший" из китайцев и прочее.
// Короче говоря, я просто рад, что решил 4/6 в div 2)

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

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
    lli n,
        k,
        l;
    cin >> n >> k >> l;
    k <<= 1; l <<= 1;
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i) {
        cin >> a[i];
        a[i] <<= 1;
    }

    if (n == 1LL) {
        lli ans = a[0] + l - k;
        cout << ans << '\n';
        return;
    }
    // now n >= 2LL

    lli cur = k,
        t = a[0];
    for (int i = 1; i < (int)n and cur < l;) {
        lli _left = a[i] - t,
            _right = a[i] + t;
        if (_left <= cur) {
            cur = min(cur, _right) + k;
            ++i;
        } else {
            /* Раньше было так:
                ++cur;
                ++t;
            */
            lli goal = (cur + _left) >> 1;
            lli dt = goal - cur;
            cur += dt;
            t += dt;
        }
    }
    if (cur < l)
        t += l - cur;
    cout << t << '\n';
    return;
}
