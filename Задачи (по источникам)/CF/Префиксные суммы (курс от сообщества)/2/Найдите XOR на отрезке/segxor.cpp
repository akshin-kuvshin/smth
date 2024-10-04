#include <iostream>
using namespace std;

const int MAX_SIZE = 1e6;

int N,
    A[MAX_SIZE + 5],
    B[MAX_SIZE + 5];

int Q,
    ans[MAX_SIZE + 5],
    l,
    r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    B[1] = A[0];
    for (int i = 1; i < N; ++i)
        B[i + 1] = B[i] ^ A[i];
    
    cin >> Q;
    for (int _q = 0; _q < Q; ++_q) {
        cin >> l >> r;
        --l;
        
        if (!l) ans[_q] = B[r];
        else ans[_q] = B[r] ^ B[l];
    }
    
    for (int _q = 0; _q < Q; ++_q)
        cout << ans[_q] << '\n';
    return 0;
}