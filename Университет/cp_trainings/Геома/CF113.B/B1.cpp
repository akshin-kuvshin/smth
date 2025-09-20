// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define x                   first
#define y                   second

#define NONE                1418LL

void solve();
lli get_cr_pr(plli A, plli B, plli C); // [AB, AC]
lli get_sign(lli num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<plli> a(n);
    for (plli& ai : a)
        cin >> ai.x >> ai.y;
    
    lli m;
    cin >> m;
    vector<plli> b(m);
    for (plli& bi : b)
        cin >> bi.x >> bi.y;
    
    lli general_sign = NONE;
    for (int i = 0; i < (int)m; ++i)
        for (int j = 0; j < (int)n; ++j) {
            lli cr_pr = get_cr_pr(
                a[j],
                a[(j + 1) % (int)n],
                b[i]
            );
            lli cr_pr_sign = get_sign(cr_pr);
            
            if (general_sign == NONE)
                general_sign = cr_pr_sign;
            
            if (cr_pr_sign != general_sign) {
                cout << "NO\n";
                return;
            }
        }
    
    cout << "YES\n";
    return;
}

lli get_cr_pr(plli A, plli B, plli C) {
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

lli get_sign(lli num) {
    if (num < 0LL)
        return -1LL;
    if (not num)
        return 0LL;
    return 1LL;
}

