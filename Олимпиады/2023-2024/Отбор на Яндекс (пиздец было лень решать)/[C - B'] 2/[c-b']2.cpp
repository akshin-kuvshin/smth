// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX = 100LL;

lli Q;
lli X,
    d[MAX],
    top,
    cnt;
lli answer;

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
    cin >> X;
    
    if (X < 7LL) {
        cout << "-1\n";
        return;
    }
    
    top = 0LL;
    while (X) {
        d[top++] = X % 2LL;
        X /= 2LL;
    }
    
    cnt = 0LL;
    for (int i = 0; i < (int)top; ++i)
        if (d[i])
            ++cnt;
    
    if (cnt == 1LL) {
        lli pos = -1LL;
        
        for (int i = (int)top - 1; i >= 0; --i)
            if (d[i]) {
                pos = i;
                break;
            }
            
        answer = (1LL << (pos - 1LL)) + (1LL << (pos - 2LL)) + (1LL << (pos - 3LL));
    } else if (cnt == 2LL) {
        lli pos1 = -1LL,
            pos2 = -1LL;
            
        for (int i = (int)top - 1; i >= 0; --i)
            if (d[i]) {
                pos1 = i;
                break;
            }
        for (int i = (int)pos1 - 1; i >= 0; --i)
            if (d[i]) {
                pos2 = i;
                break;
            }
            
        if (pos2 >= 2LL)
            answer = (1LL << pos1) + (1LL << (pos2 - 1LL)) + (1LL << (pos2 - 2LL));
        else
            answer = (1LL << (pos1 - 1LL)) + (1LL << (pos1 - 2LL)) + (1LL << (pos1 - 3LL));
    } else { // cnt >= 3LL
        lli pos1 = -1LL,
            pos2 = -1LL,
            pos3 = -1LL;
            
        for (int i = (int)top - 1; i >= 0; --i)
            if (d[i]) {
                pos1 = i;
                break;
            }
        for (int i = (int)pos1 - 1; i >= 0; --i)
            if (d[i]) {
                pos2 = i;
                break;
            }
        for (int i = (int)pos2 - 1; i >= 0; --i)
            if (d[i]) {
                pos3 = i;
                break;
            }
            
        answer = (1LL << pos1) + (1LL << pos2) + (1LL << pos3);
    }

    cout << answer << '\n';
    return;
}
