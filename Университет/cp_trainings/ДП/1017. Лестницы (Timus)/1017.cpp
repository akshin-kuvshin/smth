// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)
#define NON_DEF             -1LL

const lli MAX_SIZE = 500LL + 5LL;
lli cache[MAX_SIZE][MAX_SIZE];

void solve();
lli f(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < (int)MAX_SIZE; ++i) {
        fill(cache[i], cache[i] + MAX_SIZE, NON_DEF);
        cache[i][i] = 1LL; // set the first step
    }
    
    solve();
    
    return 0;
}

void solve() {
    lli N;
    cin >> N;
    lli answer = 0LL;
    for (lli last_step_len = 2LL; last_step_len <= N - 1LL; ++last_step_len)
        answer += f(N, last_step_len);
    cout << answer << '\n';
    return;
}

lli f(lli N, lli last) {
    if (cache[N][last] != NON_DEF)
        return cache[N][last];

    lli result = 0LL;
    for (lli prev = 1LL; prev <= min(last - 1LL, N - last); ++prev)
        result += f(N - last, prev);
    return (cache[N][last] = result);
}
