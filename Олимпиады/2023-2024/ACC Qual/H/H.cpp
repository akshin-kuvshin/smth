// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli H,
    A1,
    A2,
    C;
lli N;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> H >> A1 >> A2 >> C;
    cin >> N;

    if (A1 >= A2) {
        while (N) {
            lli input;
            cin >> input;

            if (input == -2LL)
                return;
            if (input == -1LL) {
                --N;
                continue;
            }
            
            cout << 1 << endl;
        }
        return;
    }

    ++C;
    lli cnt = 0LL;
    while (N) {
        lli input;
        cin >> input;

        if (input == -2LL)
            return;
        if (input == -1LL) {
            --N;
            cnt = 0LL;
            continue;
        }
        
        if (cnt % C == 0LL)
            cout << 2 << endl;
        else // cnt % C != 0LL
            cout << 1 << endl;

        ++cnt;
    }
    
    return;
}
