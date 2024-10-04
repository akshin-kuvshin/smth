#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 12LL;

lli p, // сколько букв можно использовать
    q, // максимум соседних одинаковых
    r, // длина плана
    n; // номер нужного плана
char S[MAX_SIZE + 5LL];
lli counter;
bool quit_flag; // флаг, если нашли нужный

void dfs(lli, lli, lli);
lli _pow(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p >> q >> r >> n;

    if (n > _pow(p, r))
        return 0;

    for (int k = 0; k < p and !quit_flag; ++k) {
        S[0] = (char)k + 'A';
        dfs(1LL, 1LL, k);
    }
    
    return 0;
}

void dfs(lli ind, lli repeats, lli last) {
    if (quit_flag)
        return;
    if (repeats > q)
        return;
    if (ind == r) {
        ++counter;
        if (counter == n) {
            for (int i = 0; i < (int)r; ++i)
                cout << S[i];
            cout << '\n';
            quit_flag = true;
        }
        return;
    }

    for (int i = 0; i < p; ++i) {
        S[ind] = (char)i + 'A';
        if (i == last)
            dfs(ind + 1LL, repeats + 1LL, i);
        else
            dfs(ind + 1LL, 1LL, i);
    }

    return;
}

lli _pow(lli base, lli power) {
    lli _ans = 1LL;
    while (power--)
        _ans *= base;
    return _ans;
}
