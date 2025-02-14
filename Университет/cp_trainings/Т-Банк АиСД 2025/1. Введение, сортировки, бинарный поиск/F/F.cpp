// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
void merge_sort(vector<lli>&, lli, lli&);
void merge_sort(vector<lli>&, lli, lli, lli&);
void mmerge(vector<lli>&, lli, lli, lli, lli&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> a[i];
    
    lli invs = 0LL;
    merge_sort(a, n, invs);
    
    cout << invs << '\n';
    for (int i = 0; i < (int)n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
    return;
}

void merge_sort(vector<lli>& a, lli n, lli& invs) {
    merge_sort(a, 0LL, n - 1LL, invs);
    return;
}

void merge_sort(vector<lli>& a, lli l, lli r, lli& invs) {
    if (l == r)
        return;
    
    lli m = (l + r) >> 1;
    merge_sort(a, l, m, invs);
    merge_sort(a, m + 1LL, r, invs);

    mmerge(a, l, m, r, invs);

    return;
}

void mmerge(vector<lli>& a, lli l, lli m, lli r, lli& invs) {
    vector<lli> X(m - l + 1LL),
                Y(r - (m + 1LL) + 1LL);
    copy(a.begin() + l, a.begin() + m + 1LL, X.begin());
    copy(a.begin() + m + 1LL, a.begin() + r + 1LL, Y.begin());

    lli ia = l,
        ix = 0LL,
        iy = 0LL;
    while (ix < m - l + 1LL and iy < r - (m + 1LL) + 1LL)
        if (X[ix] <= Y[iy]) {
            a[ia++] = X[ix++];
            invs += iy;
        } else // X[ix] > Y[iy]
            a[ia++] = Y[iy++];
    while (ix < m - l + 1LL) {
        a[ia++] = X[ix++];
        invs += iy;
    }
    while (iy < r - (m + 1LL) + 1LL)
        a[ia++] = Y[iy++];
    
    return;
}
