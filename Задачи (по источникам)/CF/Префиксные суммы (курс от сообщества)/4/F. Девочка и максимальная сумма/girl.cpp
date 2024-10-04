// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define pb(elem) push_back(elem)
#define mp(_first, _second) make_pair(_first, _second)
#define sz(object) (lli)(object).size()
#define all(object) (object).begin(), (object).end()

const lli MAX_SIZE = 200000LL;

lli N,
    A[MAX_SIZE + 5LL];
lli Q,
    l,
    r;
lli cnt[MAX_SIZE + 5LL];
lli answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    while (Q--) {
        cin >> l >> r;
        --l;

        ++cnt[l];
        --cnt[r];
    }

    for (int i = 1; i < (int)N; ++i)
        cnt[i] += cnt[i - 1];
    
    sort(A, A + N);
    sort(cnt, cnt + N);

    for (int i = 0; i < (int)N; ++i)
        answer += A[i] * cnt[i];
    cout << answer << '\n';
    
    return 0;
}
