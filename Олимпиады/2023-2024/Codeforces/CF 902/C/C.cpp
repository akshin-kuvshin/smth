// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli Q;
lli N,
    M,
    K;
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
    cin >> N >> M >> K;

    if (K > 3LL)
        answer = 0LL;
    else if (K == 1LL)
        answer = 1LL;
    else if (K == 2LL) {
        answer = (M / N) + (N - 1LL);
        answer = min(answer, M);
    } else { // K == 3LL
        answer = M - (M / N) - (N - 1LL);
        answer = max(answer, 0LL);
    }
    
    cout << answer << '\n';
    return;
}
