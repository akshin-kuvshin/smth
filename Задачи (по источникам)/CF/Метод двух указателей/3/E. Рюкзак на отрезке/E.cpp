// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define w                   first
#define c                   second

const lli MAX_SIZE = (lli)1e5 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N;
plli A[MAX_SIZE];
lli S;
lli ans = -INF;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> S;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i].w;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i].c;
    
    lli L = 0LL,
        gen_W = 0LL,
        gen_C = 0LL;
    for (lli R = 0LL; R < N; ++R) {
        gen_W += A[R].w;
        gen_C += A[R].c;

        while (gen_W > S) {
            gen_W -= A[L].w;
            gen_C -= A[L].c;
            ++L;
        }

        ans = max(ans, gen_C);
    }
    
    cout << ans << '\n';
    return;
}
