// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

#define l 0
#define r 1
#define adding 2

const lli MAX_SIZE = (lli)1e5;

lli N,
    A[MAX_SIZE + 5LL],
    d[MAX_SIZE + 5LL],

    M,
    ops[MAX_SIZE + 5LL][3],
    cnt[MAX_SIZE + 5LL],

    K,
    x,
    y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)M; ++i) {
        cin >> ops[i][l] >> ops[i][r] >> ops[i][adding];
        --ops[i][l];
    }
    


    while (K--) {
        cin >> x >> y;
        --x;

        ++cnt[x], --cnt[y];
    }
    for (int i = 1; i < (int)M; ++i)
        cnt[i] += cnt[i - 1];

    d[0] = A[0];
    for (int i = 1; i < (int)N; ++i)
        d[i] = A[i] - A[i - 1];
    for (int i = 0; i < (int)M; ++i) {
        d[ops[i][l]] += ops[i][adding] * cnt[i];
        d[ops[i][r]] -= ops[i][adding] * cnt[i];
    }

    A[0] = d[0];
    for (int i = 1; i < (int)N; ++i)
        A[i] = A[i - 1] + d[i];
    
    
    
    for (int i = 0; i < (int)N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
    return 0;
}
