// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> A(2, vector<char>(n));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < (int)n; ++j)
            cin >> A[i][j];
    
    int max_cnt = 0,
        cnt = 0;
    for (int j = 0; j + 1 < (int)n; ++j) {
        if (A[0][j] == '.' and A[1][j] == '.') {
            A[0][j] = A[1][j] = '#';
            ++cnt;
            continue;
        }

        max_cnt = max(max_cnt, cnt);
        cnt = 0;

        if (A[0][j] == '.' and A[1][j] == '#') {
            if (A[0][j + 1] == '.') {
                A[0][j] = A[0][j + 1] = '#';
                continue;
            } // else // A[0][j + 1] == '#'
            cout << "None\n";
            return;
        }
        if (A[0][j] == '#' and A[1][j] == '.') {
            if (A[1][j + 1] == '.') {
                A[1][j] = A[1][j + 1] = '#';
                continue;
            }
            cout << "None\n";
            return;
        }
    }

    // Отдельно рассматриваем последний столбец
    int j = (int)n - 1;

    if (A[0][j] != A[1][j]) {
        cout << "None\n";
        return;
    }

    if (A[0][j] == '.' and A[1][j] == '.') {
        A[0][j] = A[1][j] = '#';
        ++cnt;
    }
    max_cnt = max(max_cnt, cnt);
    cnt = 0;

    cout << ((max_cnt >= 2) ? "Multiple" : "Unique") << '\n';
    return;
}
