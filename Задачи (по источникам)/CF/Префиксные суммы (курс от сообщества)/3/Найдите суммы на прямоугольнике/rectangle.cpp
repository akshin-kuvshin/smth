#include <iostream>
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 1000LL;

lli N,
    M,
    A[MAX_SIZE + 5][MAX_SIZE + 5],
    S[MAX_SIZE + 5][MAX_SIZE + 5];
lli Q,
    lx,
    ly,
    rx,
    ry;
lli sum;

void input();
void solution();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solution();
    
    return 0;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + A[i][j];
        }
    return;
}

void solution() {
    cin >> Q;
    while (Q--) {
        cin >> lx >> ly >> rx >> ry;
        --lx, --ly;
        sum = S[rx][ry] - S[lx][ry] - S[rx][ly] + S[lx][ly];
        cout << sum << '\n';
    }
    return;
}
