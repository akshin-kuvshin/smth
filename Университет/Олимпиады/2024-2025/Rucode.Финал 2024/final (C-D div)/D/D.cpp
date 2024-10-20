// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

lli N,
    K,
    G;
vector<char> A;
vector<bool> used;
int cur_step;
char c;

void solve();
char first_non_used();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    cin >> N >> K;
    A.resize(N); used.assign(N, false);
    A[0] = 'A';
    for (int i = 1; i < (int)N; ++i)
        A[i] = A[i - 1] + 1;

    G = (N >> 1) - K;
    for (int _ = 0; _ < G; ++_) {
        cout << A[cur_step] << endl;
        cin >> c;
        used[cur_step] = used[cur_step + 1] = true;
        cur_step += 2;
    }

    while (cur_step < (int)N) {
        if (cur_step + 1 == (int)N) {
            cout << first_non_used() << endl;
            break;
        }

        if (not used[cur_step + 1]) {
            cout << A[cur_step + 1] << endl;
            used[cur_step + 1] = true;
        } else cout << first_non_used() << endl;

        cin >> c;
        used[c - 'A'] = true;

        cur_step += 2;
    }

    return;
}

char first_non_used() {
    for (int i = 0; i < (int)N; ++i)
        if (not used[i]) {
            used[i] = true;
            return A[i];
        }
    return '\0'; // в теории, мы никогда сюда не доходим
}
