#include <iostream>
#define lli long long int
using namespace std;

const int N_max = 1e6,
          Q_max = 1e6;

int N;
lli A[N_max + 5],
    B[N_max + 5];

int Q;
lli ans[Q_max + 5];
int l,
    r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    for (int i = 0; i < N; ++i)
        B[i + 1] = B[i] + A[i];
    
    cin >> Q;
    for (int _q = 0; _q < Q; ++_q) {
        cin >> l >> r;
        --l;
        
        ans[_q] = B[r] - B[l];
    }
    
    for (int _q = 0; _q < Q; ++_q)
        cout << ans[_q] << '\n';
    return 0;
}