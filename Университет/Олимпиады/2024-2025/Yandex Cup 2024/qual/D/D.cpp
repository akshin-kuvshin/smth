// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N = 1LL;
string res;
lli answer;

void solve();
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cout << N << endl;
    cin >> res;
    while (res != "ok") {
        N <<= 1;
        cout << N << endl;
        cin >> res;
    }

    answer = bs();
    cout << "! " << answer << '\n';    
    return;
}

lli bs() {
    lli l = 0LL,
        r = N;
    while (l + 1LL < r) {
        lli m = (l + r) >> 1;
        cout << m << endl;
        cin >> res;
        if (res == "wet")
            l = m;
        else // res == "ok"
            r = m;
    }
    return r;
}
