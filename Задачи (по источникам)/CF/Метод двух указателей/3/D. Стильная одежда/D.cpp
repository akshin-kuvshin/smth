// author: Danila "akshin_" Axyonov
// Честно - не ебу, почему оно работает (в контексте того, что прошлая версия не работала,
// а эта, в которой я сделал необоснованные изменения - работает; прошлые версии можете
// посмотреть в моём профиле CF "akshin_").

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define val                 first
#define ind                 second

const lli MAX_SIZE = (lli)1e5 + 5LL,
          INF = (lli)1e18 + 1LL;

lli n1,
    A1[MAX_SIZE],
    i1,
    n2,
    A2[MAX_SIZE],
    i2,
    n3,
    A3[MAX_SIZE],
    i3,
    n4,
    A4[MAX_SIZE],
    i4;
vector<lli> best_v;
lli best_d = INF;

void solve();
plli calc(vector<lli>); // return (d, ind_to_increment)
bool by_val(const plli&, const plli&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> n1;
    for (int i = 0; i < (int)n1; ++i)
        cin >> A1[i];
    sort(A1, A1 + n1);
    cin >> n2;
    for (int i = 0; i < (int)n2; ++i)
        cin >> A2[i];
    sort(A2, A2 + n2);
    cin >> n3;
    for (int i = 0; i < (int)n3; ++i)
        cin >> A3[i];
    sort(A3, A3 + n3);
    cin >> n4;
    for (int i = 0; i < (int)n4; ++i)
        cin >> A4[i];
    sort(A4, A4 + n4);
    
    while (i1 < n1 and i2 < n2 and i3 < n3 and i4 < n4) {
        plli res = calc({A1[i1], A2[i2], A3[i3], A4[i4]});
        if (res.first < best_d) {
            best_v = {A1[i1], A2[i2], A3[i3], A4[i4]};
            best_d = res.first;
        }
        switch (res.second) {
            case 1LL:
                ++i1;
                break;
            case 2LL:
                ++i2;
                break;
            case 3LL:
                ++i3;
                break;
            case 4LL:
                ++i4;
                break;
            default: // теоретически, недостижимо
                cerr << "ERROR\n";
                return;
        }
    }
    
    for (lli elem : best_v)
        cout << elem << ' ';
    cout << '\n';
    return;
}

plli calc(vector<lli> vals) {
    vector<plli> v = {mp(vals[0], 1LL),
                      mp(vals[1], 2LL),
                      mp(vals[2], 3LL),
                      mp(vals[3], 4LL)};
    sort(v.begin(), v.end(), by_val);

    lli d = v.back().first - v.front().first;
    
    return mp(d, v[0].second);
}

bool by_val(const plli &p1, const plli &p2) { return p1.val <= p2.val; }
