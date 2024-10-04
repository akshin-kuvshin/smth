#include <iostream>
using namespace std;
typedef long long int lli;

lli N,
    x,
    y;
lli answer;

bool f(lli);
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> x >> y;

    answer = min(x, y);
    --N;
    if (N)
        answer += bs();

    cout << answer << '\n';
    return 0;
}

bool f(lli time) {
    lli s = (time / x) + (time / y);
    return (s >= N);
}

lli bs() {
    lli l = 0LL,
        r = (lli)1e9;
    
    while (l + 1LL < r) {
        lli m = (l + r) / 2LL;

        if (!f(m))
            l = m;
        else
            r = m;
    }

    return r;
}
