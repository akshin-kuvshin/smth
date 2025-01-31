// author: Danila "akshin_" Axyonov
// don't know is it good or no, but i've read editorial before i solved the problem

// Пусть последний выбранный нами элемент стоит на позиции l.
// Посмотрим на два значения: минимума на суффиксе [l+1..n-1] и минимума среди элементов в массиве others.
// 1. Если значение на суффиксе меньше или равно минимума из others, то добавим это значение в ответ,
// а все элементы между l и новым значением увеличим на 1 и добавим в массив others. Повторим проверку
// с новым значением l.
// 2. Иначе добавим в others весь суффикс [l+1..n-1] (каждый элемент увеличив на 1) и закончим цикл.
// В конце-концов отсортируем others и запишем в конец ответа.
// Короче говоря, действуем жадно.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

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
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    
    vector<plli> a_suf_min(n);
    a_suf_min.back() = {a.back(), n - 1LL};
    for (int i = (int)n - 2; i >= 0; --i)
        if (a[i] <= a_suf_min[i + 1].first)
            a_suf_min[i] = {a[i], (lli)i};
        else // a[i] > a_suf_min[i + 1].first
            a_suf_min[i] = a_suf_min[i + 1];
    
    vector<lli> res,
                other;
    lli other_min = INF;
    lli l = -1LL;
    while (l + 1LL < (int)n) {
        plli pr = a_suf_min[l + 1LL];

        if (pr.first <= other_min) {
            res.pb(pr.first);
            for (lli i = l + 1LL; i < pr.second; ++i) {
                other.pb(a[i] + 1LL);
                other_min = min(other_min, other.back());
            }
            l = pr.second;
        } else { // other_min < pr.second
            for (lli i = l + 1LL; i < n; ++i)
                other.pb(a[i] + 1LL);
            break;
        }
    }
    sort(other.begin(), other.end());
    copy(other.begin(), other.end(), back_inserter(res));

    for (lli elem : res)
        cout << elem << ' ';
    cout << '\n';
    return;
}
