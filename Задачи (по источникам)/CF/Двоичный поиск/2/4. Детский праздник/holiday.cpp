#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 1000LL;

lli M,
    N,
    t[MAX_SIZE + 5LL],
    z[MAX_SIZE + 5LL],
    y[MAX_SIZE + 5LL];
lli answer;
lli d[MAX_SIZE + 5LL]; // distribution - распределение

bool f(lli);
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> t[i] >> z[i] >> y[i];
    
    if (!M) { // M == 0LL
        cout << 0 << '\n';
        for (int i = 0; i < (int)N; ++i)
            cout << 0 << ' ';
        cout << '\n';
        return 0;
    }
    
    answer = bs();
    
    lli counter = 0LL;
    for (int i = 0; i < (int)N; ++i) {
        d[i] += (answer / (t[i] * z[i] + y[i])) * z[i];
        d[i] += min(z[i], (answer % (t[i] * z[i] + y[i])) / t[i]);
        counter += d[i];
    }
    for (int i = 0; i < (int)N and counter > M; ++i) {
        lli _d = min(d[i], counter - M);
        d[i] -= _d;
        counter -= _d;
    }

    cout << answer << '\n';
    for (int i = 0; i < (int)N; ++i)
        cout << d[i] << ' ';
    cout << '\n';
    return 0;
}

bool f(lli time) {
    lli counter = 0LL;
    for (int i = 0; i < (int)N; ++i) {
        counter += (time / (t[i] * z[i] + y[i])) * z[i];
        counter += min(z[i], (time % (t[i] * z[i] + y[i])) / t[i]);
    }
    return (counter >= M);
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
