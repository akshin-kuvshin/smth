// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
lli N;
vector<int> A;
char c;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < (int)N; ++i) {
        cin >> c;
        A[i] = (lli)(c - '0');
    }

    if (A.front() or A.back()) {
        cout << "YES\n";
        return;
    }

    // now we have sequence, starting and ending with 0
    lli len = 0LL;
    for (int i = 0; i < (int)N; ++i)
        if (A[i]) ++len;
        else {
            if (len >= 2LL) {
                cout << "YES\n";
                return;
            }
            len = 0LL;
        }
    
    cout << "NO\n";
    return;
}
