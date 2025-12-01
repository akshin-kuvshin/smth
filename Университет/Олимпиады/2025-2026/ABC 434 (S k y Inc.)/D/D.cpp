// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli SIZE = 2000LL;

struct Cloud {
    lli r1;
    lli r2;
    lli c1;
    lli c2;
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    vector<vector<lli>> field(SIZE + 1LL, vector<lli>(SIZE + 1LL));

    lli n;
    cin >> n;
    vector<Cloud> a(n);
    for (auto& ai : a) {
        cin >> ai.r1 >> ai.r2 >> ai.c1 >> ai.c2;
        --ai.r1;
        --ai.r2;
        --ai.c1;
        --ai.c2;

        field[ai.r1][ai.c1] += 1LL;
        field[ai.r2 + 1LL][ai.c1] -= 1LL;
        field[ai.r1][ai.c2 + 1LL] -= 1LL;
        field[ai.r2 + 1LL][ai.c2 + 1LL] += 1LL;
    }

    for (int i = 1; i < (int)SIZE; ++i) {
        field[0][i] += field[0][i - 1];
        field[i][0] += field[i - 1][0];
    }
    for (int i = 1; i < (int)SIZE; ++i)
        for (int j = 1; j < (int)SIZE; ++j)
            field[i][j] += field[i - 1][j] + field[i][j - 1] - field[i - 1][j - 1];

    lli zeros = 0LL;
    for (int i = 0; i < (int)SIZE; ++i)
        for (int j = 0; j < (int)SIZE; ++j) {
            zeros += (field[i][j] == 0LL);
            field[i][j] = (field[i][j] == 1LL);
        }

    for (int i = 1; i < (int)SIZE; ++i) {
        field[0][i] += field[0][i - 1];
        field[i][0] += field[i - 1][0];
    }
    for (int i = 1; i < (int)SIZE; ++i)
        for (int j = 1; j < (int)SIZE; ++j)
            field[i][j] += field[i - 1][j] + field[i][j - 1] - field[i - 1][j - 1];

    for (auto [r1, r2, c1, c2] : a) {
        lli misses = field[r2][c2];
        if (r1 != 0LL)
            misses -= field[r1 - 1LL][c2];
        if (c1 != 0LL)
            misses -= field[r2][c1 - 1LL];
        if (r1 != 0LL and c1 != 0LL)
            misses += field[r1 - 1LL][c1 - 1LL];

        cout << zeros + misses << '\n';
    }
    return;
}
