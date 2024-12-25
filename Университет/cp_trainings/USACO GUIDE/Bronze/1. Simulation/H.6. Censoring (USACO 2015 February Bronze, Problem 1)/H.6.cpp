// author: Danila "akshin_" Axyonov

#include <fstream>
#include <string>
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
    cin.open("censor.in");
    cin.tie(nullptr);
    ofstream cout;
    cout.open("censor.out");

    string S,
           T;
    cin >> S >> T;
    size_t T_len = T.size();
    
    size_t cur = 0ULL;
    while ((cur = S.find(T, cur)) != string::npos) {
        S.erase(cur, T_len);
        cur = ((cur >= T_len - 1ULL) ? (cur - T_len + 1ULL) : 0ULL);
    }
    cout << S << '\n';

    cin.close();
    cout.close();
    return;
}
