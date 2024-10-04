#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

lli Q;
lli N,
    M;
vector<vector<lli>> C;
vector<lli> sums;
lli answer;

void input();
void solution();
void output();

int main() {
    cin >> Q;
    while (Q--) {
        input();
        solution();
        output();
    }
    
    return 0;
}

void input() {
    cin >> N >> M;

    C.resize(M);
    for (int i = 0; i < (int)M; ++i)
        C[i].resize(N);
    sums.resize(M);
    fill(sums.begin(), sums.end(), 0LL);
    
    for (int j = 0; j < (int)N; ++j)
        for (int i = 0; i < (int)M; ++i) {
            cin >> C[i][j];
            sums[i] += C[i][j];
        }
    
    return;
}

void solution() {
    for (int i = 0; i < (int)M; ++i)
        sort(C[i].begin(), C[i].end());

    answer = 0LL;
    for (int i = 0; i < (int)M; ++i)
        for (int j = 0; j + 1 < (int)N; ++j) {
            sums[i] -= C[i][j];
            answer += sums[i] - C[i][j] * (N - (lli)j - 1LL);
        }

    return;
}

void output() {
    cout << answer << '\n';
    return;
}
