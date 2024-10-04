// author: Danila "akshin_" Aksionov

#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 100LL;

lli N,
    M;
string T[MAX_SIZE + 5LL],
       Q[MAX_SIZE + 5LL];
lli D0,
    D[MAX_SIZE + 5LL];
lli difficulty;
bool is_found;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> T[i];
    for (int j = 0; j < (int)M; ++j)
        cin >> Q[j];
    cin >> D0;
    for (int j = 0; j < (int)M; ++j)
        cin >> D[j];

    for (int i = 0; i < (int)N; ++i) {
        is_found = false;
        for (int j = 0; j < (int)M and !is_found; ++j)
            if (T[i] == Q[j]) {
                difficulty += D[j];
                is_found = true;
            }
        
        if (!is_found)
            difficulty += D0;
    }

    cout << difficulty << '\n';
    return;
}
