// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)
#define x                   first
#define y                   second

plli A,
     B,
     C;
plli O;

void solve();
lli crpr(plli, plli);
lli _sign(lli);

plli operator-(plli v1, plli v2) {
    return mp(
        v1.x - v2.x,
        v1.y - v2.y
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    plli AB = B - A,
         AC = C - A,
         AO = O - A,
         BC = C - B,
         BA = A - B,
         BO = O - B,
         CA = A - C,
         CB = B - C,
         CO = O - C;
    if ((_sign(crpr(AB, AC)) == _sign(crpr(AO, AC)) and
         _sign(crpr(BC, BA)) == _sign(crpr(BO, BA)) and
         _sign(crpr(CA, CB)) == _sign(crpr(CO, CB))) or
        _sign(crpr(AO, AC)) == 0LL or
        _sign(crpr(BO, BA)) == 0LL or
        _sign(crpr(CO, CB)) == 0LL) {
        cout << "987654321\n";
        return;
    }

    cout << -A.x << ' ' << -A.y << ' ' << -B.x << ' ' << -B.y << ' ' << -C.x << ' ' << -C.y << '\n';    
    return;
}

lli crpr(plli v1, plli v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

// num != 0LL
lli _sign(lli num) {
    if (num > 0LL)
        return 1LL;
    if (num == 0LL)
        return 0LL;
    return -1LL;
}
