#include <iostream>
#include <array>
using namespace std;

using lli = long long int;
 
const int N_max = 1e6;
 
int N;
array<lli, N_max + 5> A,
                      B;
 
int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    for (int i = 0; i < N; ++i)
        B[i + 1] = B[i] + A[i];
    
    for (int i = 0; i <= N; ++i)
        cout << B[i] << '\n';
    return 0;
}