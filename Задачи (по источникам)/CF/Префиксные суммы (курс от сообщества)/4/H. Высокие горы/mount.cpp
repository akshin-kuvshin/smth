// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

#define num first
#define index second

const lli MAX_SIZE = 100000LL;

lli N;
pair<lli, lli> A[MAX_SIZE + 5LL];
lli D[MAX_SIZE + 5LL];              // D[i] = A[i].num - A[i - 1].num;
lli Q,
    k,
    x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        lli tmp;
        cin >> tmp;
        A[i] = mp(tmp, i);
    }

    sort(A, A + N, [](pair<lli, lli> p1, pair<lli, lli> p2) -> bool {
        return p1.num < p2.num;
    });

    D[0] = A[0].num;
    for (int i = 1; i < (int)N; ++i)
        D[i] = A[i].num - A[i - 1].num;
    
    cin >> Q;
    while (Q--) {
        cin >> k >> x;
        D[N - k] += x;
    }

    A[0].num = D[0];
    for (int i = 1; i < (int)N; ++i)
        A[i].num = A[i - 1].num + D[i];
    
    /* sort(A, A + N, [](pair<lli, lli> p1, pair<lli, lli> p2) -> bool {
        return p1.index < p2.index;
    }); */

    for (int i = 0; i < (int)N; ++i)
        cout << A[i].num << ' ';
    cout << '\n';
    
    return 0;
}
