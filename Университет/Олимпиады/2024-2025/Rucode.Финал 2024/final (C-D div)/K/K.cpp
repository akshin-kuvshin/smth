// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

lli N;
vector<pair<char, lli>> A;
lli start = 1LL;
char name;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    cin >> N;

    while (start <= N) {
        cout << "? " << start << endl;
        cin >> name;

        lli l = start,
            r = N + 1LL;
        while (l + 1LL < r) {
            lli m = (l + r) >> 1;

            char res;
            cout << "? " << m << endl;
            cin >> res;

            if (res == name)
                l = m;
            else
                r = m;
        }

        A.push_back(make_pair(name, r - 1LL));
        start = r;
    }

    cout << "! ";
    for (pair<char, lli> p : A)
        cout << p.first << ' ' << p.second << ' ';
    cout << endl;
    return;
}
