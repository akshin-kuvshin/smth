// author: Danila "akshin_" Axyonov

#include <fstream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
lli _abs(lli);

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin;
    cin.open("lostcow.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("lostcow.out");

    lli x,
        y;
    cin >> x >> y;
    ++x;

    lli dist = 1LL,
        cur = 1LL,
        sign = -1LL;
    if (x < y) while (x < y) {
        lli new_x = min(x + 3LL * cur * sign, y);
        dist += _abs(new_x - x);

        x = new_x;
        cur <<= 1;
        sign *= -1LL;
    } else /* x > y */ while (x > y) {
        lli new_x = max(x + 3LL * cur * sign, y);
        dist += _abs(new_x - x);

        x = new_x;
        cur <<= 1;
        sign *= -1LL;
    }
    
    cout << dist << '\n';

    cin.close();
    cout.close();
    return;
}

lli _abs(lli num) {
    return (num >= 0LL ? num : -num);
}
