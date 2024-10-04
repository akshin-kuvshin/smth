#include <iostream>
using namespace std;

typedef long long int lli;

const lli MAX_SZ = 16LL,
          dimensions = 5LL;

lli N[dimensions + 5LL],
    A[MAX_SZ + 5LL][MAX_SZ + 5LL][MAX_SZ + 5LL][MAX_SZ + 5LL][MAX_SZ + 5LL],
    S[MAX_SZ + 5LL][MAX_SZ + 5LL][MAX_SZ + 5LL][MAX_SZ + 5LL][MAX_SZ + 5LL];
lli Q,
    l1, l2, l3, l4, l5,
    r1, r2, r3, r4, r5;
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
    for (lli d = 0LL; d < dimensions; ++d)
        cin >> N[d];
    for (lli i = 0LL; i < N[0]; ++i)
        for (lli j = 0LL; j < N[1]; ++j)
            for (lli k = 0LL; k < N[2]; ++k)
                for (lli e = 0LL; e < N[3]; ++e)
                    for (lli f = 0LL; f < N[4]; ++f) {
                        cin >> A[i][j][k][e][f];
                        S[i + 1][j + 1][k + 1][e + 1][f + 1] = S[i][j + 1][k + 1][e + 1][f + 1]
                                                             + S[i + 1][j][k + 1][e + 1][f + 1]
                                                             + S[i + 1][j + 1][k][e + 1][f + 1]
                                                             + S[i + 1][j + 1][k + 1][e][f + 1]
                                                             + S[i + 1][j + 1][k + 1][e + 1][f]
                                                             - S[i][j][k + 1][e + 1][f + 1]
                                                             - S[i][j + 1][k][e + 1][f + 1]
                                                             - S[i][j + 1][k + 1][e][f + 1]
                                                             - S[i][j + 1][k + 1][e + 1][f]
                                                             - S[i + 1][j][k][e + 1][f + 1]
                                                             - S[i + 1][j][k + 1][e][f + 1]
                                                             - S[i + 1][j][k + 1][e + 1][f]
                                                             - S[i + 1][j + 1][k][e][f + 1]
                                                             - S[i + 1][j + 1][k][e + 1][f]
                                                             - S[i + 1][j + 1][k + 1][e][f]
                                                             + S[i][j][k][e + 1][f + 1]
                                                             + S[i][j][k + 1][e][f + 1]
                                                             + S[i][j][k + 1][e + 1][f]
                                                             + S[i][j + 1][k][e][f + 1]
                                                             + S[i][j + 1][k][e + 1][f]
                                                             + S[i][j + 1][k + 1][e][f]
                                                             + S[i + 1][j][k][e][f + 1]
                                                             + S[i + 1][j][k][e + 1][f]
                                                             + S[i + 1][j][k + 1][e][f]
                                                             + S[i + 1][j + 1][k][e][f]
                                                             - S[i][j][k][e][f + 1]
                                                             - S[i][j][k][e + 1][f]
                                                             - S[i][j][k + 1][e][f]
                                                             - S[i][j + 1][k][e][f]
                                                             - S[i + 1][j][k][e][f]
                                                             + S[i][j][k][e][f]
                                                             + A[i][j][k][e][f];
                    }
}

void solution() {
    cin >> Q;
    while (Q--) {
        cin >> l1 >> l2 >> l3 >> l4 >> l5 >> r1 >> r2 >> r3 >> r4 >> r5;
        --l1, --l2, --l3, --l4, --l5;
        sum = S[r1][r2][r3][r4][r5]
            - S[l1][r2][r3][r4][r5]
            - S[r1][l2][r3][r4][r5]
            - S[r1][r2][l3][r4][r5]
            - S[r1][r2][r3][l4][r5]
            - S[r1][r2][r3][r4][l5]
            + S[l1][l2][r3][r4][r5]
            + S[l1][r2][l3][r4][r5]
            + S[l1][r2][r3][l4][r5]
            + S[l1][r2][r3][r4][l5]
            + S[r1][l2][l3][r4][r5]
            + S[r1][l2][r3][l4][r5]
            + S[r1][l2][r3][r4][l5]
            + S[r1][r2][l3][l4][r5]
            + S[r1][r2][l3][r4][l5]
            + S[r1][r2][r3][l4][l5]
            - S[l1][l2][l3][r4][r5]
            - S[l1][l2][r3][l4][r5]
            - S[l1][l2][r3][r4][l5]
            - S[l1][r2][l3][l4][r5]
            - S[l1][r2][l3][r4][l5]
            - S[l1][r2][r3][l4][l5]
            - S[r1][l2][l3][l4][r5]
            - S[r1][l2][l3][r4][l5]
            - S[r1][l2][r3][l4][l5]
            - S[r1][r2][l3][l4][l5]
            + S[l1][l2][l3][l4][r5]
            + S[l1][l2][l3][r4][l5]
            + S[l1][l2][r3][l4][l5]
            + S[l1][r2][l3][l4][l5]
            + S[r1][l2][l3][l4][l5]
            - S[l1][l2][l3][l4][l5];
        cout << sum << '\n';
    }
    return;
}
