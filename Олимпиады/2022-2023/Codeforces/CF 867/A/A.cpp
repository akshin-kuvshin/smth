// author: Danila "akshin_" Aksionov

#include <iostream>
#define NO_ANSWER -1LL
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 50LL;

lli Q;
lli N,
    t,
    A[MAX_SIZE + 5LL],
    B[MAX_SIZE + 5LL];
lli t_required[MAX_SIZE + 5LL];
lli current_interest;
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
    cin >> N >> t;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)N; ++i)
        cin >> B[i];
    
    for (int i = 0; i < (int)N; ++i)
        t_required[i] = i + A[i];
    
    current_interest = answer = NO_ANSWER;
    for (int i = 0; i < (int)N; ++i)
        if (t_required[i] <= t and current_interest < B[i]) {
            current_interest = B[i];
            answer = i;
        }
    
    cout << (answer == NO_ANSWER ? answer : answer + 1LL) << '\n';
    return;
}
