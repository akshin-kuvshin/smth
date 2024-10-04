#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 300LL;

string S;
lli N;
lli x[MAX_SIZE];
lli cur[MAX_SIZE];
lli ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(x, x + MAX_SIZE, -1LL);
    fill(cur, cur + MAX_SIZE, -1LL);

    cin >> S;
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        char tmp;
        cin >> tmp;
        cin >> x[tmp];
    }

    for (char c : S) {
        if (x[c] == -1LL) {
            ++ans;
            continue;
        }

        if (cur[c] == 0LL) {
            ans += 2LL;
            cur[c] = (cur[c] + 2LL) % x[c];
        } else {
            ++ans;
            cur[c] = (cur[c] + 1LL) % x[c];
        }
    }

    for (char c = 'a'; c <= 'z'; ++c)
        if (x[c] != -1LL and !cur[c])
            ++ans;

    cout << ans << '\n';
    return 0;
}
