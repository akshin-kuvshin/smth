// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)5e5 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N;
lli K,
    A[MAX_SIZE],
    B[MAX_SIZE],
    B_rev[MAX_SIZE];
lli ind_B[MAX_SIZE],
    ind_B_rev[MAX_SIZE];
unordered_map<lli, lli> shift,
                        shift_rev;
bool used[MAX_SIZE];
lli answer;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < (int)K; ++i) {
        cin >> A[i];
        --A[i];
        used[A[i]] = true;
    }
    for (int i = 0; i < (int)K; ++i) {
        cin >> B[i];
        --B[i];
        used[B[i]] = true;
    }

    copy(B, B + K, B_rev);
    reverse(B_rev, B_rev + K);
    fill(ind_B, ind_B + N, -1LL);
    fill(ind_B_rev, ind_B_rev + N, -1LL);
    for (int i = 0; i < (int)K; ++i)
        ind_B[B[i]] = (lli)i;
    for (int i = 0; i < (int)K; ++i)
        ind_B_rev[B_rev[i]] = (lli)i;
    
    for (int i = 0; i < (int)K; ++i)
        if (ind_B[A[i]] != -1LL)
            ++shift[(ind_B[A[i]] - (lli)i + K) % K];
    for (int i = 0; i < (int)K; ++i)
        if (ind_B_rev[A[i]] != -1LL)
            ++shift_rev[(ind_B_rev[A[i]] - (lli)i + K) % K];
    
    lli ans0 = -INF;
    for (plli p : shift) {
        // cerr << "shift = " << p.first << ", amount = " << p.second << '\n';
        ans0 = max(ans0, p.second);
    }
    for (plli p : shift_rev) {
        // cerr << "shift_rev = " << p.first << ", amount = " << p.second << '\n';
        ans0 = max(ans0, p.second);
    }
    answer += max(ans0, 0LL);

    for (int i = 0; i < (int)N; ++i)
        if (!used[i])
            ++answer;
    
    cout << answer << '\n';
    return;
}
