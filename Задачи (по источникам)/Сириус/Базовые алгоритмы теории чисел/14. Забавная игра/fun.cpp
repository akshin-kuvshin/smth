// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          A_MAX = (lli)1e3 + 5LL;

bool p[A_MAX];
lli primes[A_MAX],
    top;

lli N,
    A[MAX_SIZE];
lli ans;

void get_primes();
void solve();
lli count_ans(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    get_primes();
    solve();
    
    return 0;
}

void get_primes() {
    fill(p, p + A_MAX, true);
    p[0] = p[1] = false;
    for (lli i = 2LL; i * i < A_MAX; ++i) {
        if (!p[i])
            continue;
        for (lli j = i * i; j < A_MAX; j += i)
            p[j] = false;
    }

    for (int i = 0; i < (int)A_MAX; ++i)
        if (p[i])
            primes[top++] = (lli)i;
    
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    for (int i = 0; i < (int)top; ++i)
        ans = max(ans, count_ans(primes[i]));

    cout << ans << '\n';
    return;
}

lli count_ans(lli x) {
    lli cur = 0LL, // len
        _max = 0LL; // len
    for (int i = 0; i < (int)N; ++i)
        if (A[i] % x == 0LL)
            ++cur;
        else { // A[i] % x != 0LL
            _max = max(_max, cur);
            cur = 0LL;
        }
    _max = max(_max, cur);
    return _max;
}
