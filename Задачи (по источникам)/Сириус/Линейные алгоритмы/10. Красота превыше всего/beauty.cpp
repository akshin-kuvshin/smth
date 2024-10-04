// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)3e5 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N,
    A[MAX_SIZE];
lli K,
    cnt[MAX_SIZE],
    S;
plli ans = mp(-INF, INF);

void add(lli);
bool good();
void remove(lli);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    lli L = 0LL;
    for (lli R = 0LL; R < N; ++R) {
        add(A[R]);
        while (good()) {
            if (R - L < ans.second - ans.first)
                ans = mp(L, R);
            remove(A[L++]);
        }
    }
    
    cout << (ans.first + 1LL) << ' ' << (ans.second + 1LL) << '\n';
    return;
}

void add(lli x) {
    ++cnt[x];
    if (cnt[x] == 1LL)
        ++S;
    return;
}

bool good() { return S == K; }

void remove(lli x) {
    --cnt[x];
    if (cnt[x] == 0LL)
        --S;
    return;
}
