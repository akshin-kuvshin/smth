#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 200000LL;

string t,
       p;
lli N,
    M,
    A[MAX_SIZE + 5LL];
lli answer;
bool deleted[MAX_SIZE + 5LL];

bool f(lli);
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> p;
    N = (lli)t.size();
    M = (lli)p.size();
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        --A[i];
    }
    
    answer = bs();
    cout << answer << '\n';
    return 0;
}

bool f(lli x) {
    fill(deleted, deleted + N, false);
    for (int i = 0; i < x; ++i)
        deleted[A[i]] = true;
    
    lli i = 0LL,
        j = 0LL;
    while (i < N and j < M) {
        if (deleted[i]) {
            ++i;
            continue;
        }

        if (t[i] == p[j]) {
            ++i; ++j;
        } else {
            ++i;
        }
    }

    return (j == M);
}

lli bs() {
    lli l = 0LL,
        r = N;
    
    while (l + 1LL < r) {
        lli m = (l + r) / 2LL;

        if (f(m))
            l = m;
        else
            r = m;
    }

    return l;
}
