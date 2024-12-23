// author: Danila "akshin_" Axyonov

#include <fstream>
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
    cin.open("shuffle.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("shuffle.out");

    lli n;
    cin >> n;
    vector<lli> p_tmp(n),
                p(n);
    for (int i = 0; i < (int)n; ++i) {
        cin >> p_tmp[i];
        --p_tmp[i];
        p[p_tmp[i]] = (lli)i;
    }

    vector<lli> a(n),
                tmp(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    for (int _ = 0; _ < 3; ++_) {
        for (int i = 0; i < (int)n; ++i)
            tmp[p[i]] = a[i];
        copy(tmp.begin(), tmp.end(), a.begin());
    }

    for (lli cow : a)
        cout << cow << '\n';
    
    cin.close();
    cout.close();
    return;
}
