#include <iostream>
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 50LL;

lli N,
    x,
    y;
char s[MAX_SIZE + 5LL];
bool answer;
lli Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--) {
        x = y = 0LL;
        answer = false;

        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> s[i];
            if (s[i] == 'L') --x;
            else if (s[i] == 'R') ++x;
            else if (s[i] == 'D') --y;
            else ++y;

            if ((x == 1) and (y == 1))
                answer = true;
        }

        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
