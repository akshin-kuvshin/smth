// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e5;

lli N,
    A[MAX_SIZE + 5LL],
    B[MAX_SIZE + 5LL];
bool used[MAX_SIZE + 5LL];
lli cnt,
    answer;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)N; ++i)
        cin >> B[i];
    
    for (int i = 0, to_find = 0; i < (int)N and to_find < (int)N;) {
        if (used[A[i]]) {
            ++i;
            continue;
        }

        if (A[i] == B[to_find]) {
            ++i;
            ++to_find;
        } else {
            used[B[to_find]] = true;
            ++to_find;
            ++answer;
        }
    }

    cout << answer << '\n';
    return;
}
