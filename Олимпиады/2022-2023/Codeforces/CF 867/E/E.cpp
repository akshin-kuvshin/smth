// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 200000LL,
          LETTERS_NUMBER = 26LL;

lli Q;
lli N;
char S[MAX_SIZE + 5LL];
lli counter[LETTERS_NUMBER + 5LL];
lli repeats[LETTERS_NUMBER + 5LL];
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
    fill(counter, counter + LETTERS_NUMBER, 0LL);
    fill(repeats, repeats + LETTERS_NUMBER, 0LL);

    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> S[i];
        ++counter[S[i] - 'a'];
    }
    
    if (N & 1LL) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < (int)LETTERS_NUMBER; ++i)
        if (counter[i] > N / 2LL) {
            cout << "-1\n";
            return;
        }
    
    // Думаем о хорошем
    lli half_N = N / 2LL;
    for (int i = 0; i < half_N; ++i) {
        if (S[i] != S[N - i - 1LL]) continue;
        ++repeats[S[i] - 'a'];
    }

    answer = 0LL;
    sort(repeats, repeats + LETTERS_NUMBER);
    lli _sum_without_last = 0LL;
    for (int i = 0; i + 1 < (int)LETTERS_NUMBER; ++i)
        _sum_without_last += repeats[i];
    if (repeats[LETTERS_NUMBER - 1LL] > _sum_without_last)
        answer = repeats[LETTERS_NUMBER - 1LL];
    else {
        lli _sum = _sum_without_last + repeats[LETTERS_NUMBER - 1LL];
        answer = _sum / 2LL + (_sum & 1LL);
    }

    cout << answer << '\n';
    return;
}
