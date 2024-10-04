// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli N;
    cin >> N;

    vector<lli> x(N - 1LL);
    for (int i = 0; i + 1 < (int)N; ++i)
        cin >> x[i];
    
    vector<lli> A(N);
    A[0] = x[0] + 1LL;
    for (int i = 1; i + 1 < (int)N; ++i) {
        lli k = (x[i] - x[i - 1] + A[i - 1] - 1LL) / A[i - 1];
        k = max(k, 0LL);
        A[i] = x[i - 1] + k * A[i - 1];
        if (A[i] == x[i])
            A[i] += A[i - 1];
    }
    A[N - 1LL] = x[N - 2LL];
    
    for (int i = 0; i < (int)N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
    return;
}
