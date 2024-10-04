// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

lli N,
    M;
lli k,
    k2;
lli score_diff; // diff = Glen - computer

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    cin >> k;

    if (N < M)
        swap(N, M);
    k2 = (k << 1); // k2 = 2 * k

    if (N != M) {
        lli rectangle_d = N - M;
        
        if (k2 <= rectangle_d) {
            cout << "0 0\n";
            return;
        }

        if (rectangle_d & 1LL)
            score_diff += N;
        k2 -= rectangle_d;
    }

    lli paired_steps = (k2 >> 1);
    if (k2 & 1LL)
        score_diff -= N; // score_diff += paired_steps - (N + paired_steps)
    else
        score_diff -= paired_steps;

    if (!score_diff)
        cout << "0 " << score_diff << '\n';
    else if (score_diff > 0LL)
        cout << "1 " << score_diff << '\n';
    else 
        cout << "2 " << -score_diff << '\n';
    
    return;
}
