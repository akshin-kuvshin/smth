// author: Danila "akshin_" Axyonov

#include <fstream>
#include <map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define x                   first
#define y                   second
#define used                first
#define t                   second

const lli INF = (lli)1e18 + 1LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin;
    cin.open("mowing.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("mowing.out");

    map<char, plli> dir;
    dir['N'] = mp(0LL, 1LL);
    dir['E'] = mp(1LL, 0LL);
    dir['S'] = mp(0LL, -1LL);
    dir['W'] = mp(-1LL, 0LL);

    map<plli, pair<bool, lli>> m;
    lli ans = INF;

    plli pos = mp(0LL, 0LL);
    lli time = 0LL;
    m[pos] = mp(true, time++);

    lli n;
    cin >> n;
    while (n--) {
        char cmd;
        lli len;
        cin >> cmd >> len;

        while (len--) {
            pos.x += dir[cmd].x;
            pos.y += dir[cmd].y;
            if (not m[pos].used)
                m[pos] = mp(true, time);
            else { // m[pos].used
                ans = min(ans, time - m[pos].t);
                m[pos].t = time;
            }
            ++time;
        }
    }
    
    cout << ((ans == INF) ? -1LL : ans) << '\n';
    cin.close();
    cout.close();
    return;
}
