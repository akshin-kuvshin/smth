// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N,
    A[MAX_SIZE],
    M,
    B[MAX_SIZE];
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int j = 0; j < (int)M; ++j)
        cin >> B[j];
    
    lli ind = 0LL,
        j = 0LL;
    while (j < M) {
        lli elem = B[j],
            cnt_B = 0LL;
        while (j < M and B[j] == elem) {
            ++cnt_B;
            ++j;
        }

        lli cnt_A = 0LL;
        while (ind < N and A[ind] <= elem) {
            if (A[ind] == elem)
                ++cnt_A;
            ++ind;
        }

        ans += cnt_A * cnt_B;
    }

    cout << ans << '\n';
    return;
}
