// author: Danila "akshin_" Axyonov

#include <fstream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin;
    cin.open("traffic.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("traffic.out");

    lli n;
    cin >> n;
    vector<string> cmd(n);
    vector<plli> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> cmd[i] >> a[i].first >> a[i].second;

    plli finish;
    {
        int i = 0;
        while (cmd[i] != "none") ++i;
        finish = a[i++];
        while (i < (int)n) {
            if (cmd[i] == "none") {
                finish.first = max(finish.first, a[i].first);
                finish.second = min(finish.second, a[i].second);
            } else if (cmd[i] == "on") {
                finish.first += a[i].first;
                finish.second += a[i].second;
            } else { // cmd[i] == "off"
                finish.first -= a[i].second;
                finish.first = max(finish.first, 0LL);
                finish.second -= a[i].first;
                finish.second = max(finish.second, 0LL);
            }
            ++i;
        }
    }
    
    plli start;
    {
        int i = (int)n - 1;
        while (cmd[i] != "none") --i;
        start = a[i--];
        while (i >= 0) {
            if (cmd[i] == "none") {
                start.first = max(start.first, a[i].first);
                start.second = min(start.second, a[i].second);
            } else if (cmd[i] == "off") {
                start.first += a[i].first;
                start.second += a[i].second;
            } else { // cmd[i] == "on"
                start.first -= a[i].second;
                start.first = max(start.first, 0LL);
                start.second -= a[i].first;
                start.second = max(start.second, 0LL);
            }
            --i;
        }
    }
    
    cout << start.first << ' ' << start.second << '\n' << finish.first << ' ' << finish.second << '\n';

    cin.close();
    cout.close();
    return;
}
