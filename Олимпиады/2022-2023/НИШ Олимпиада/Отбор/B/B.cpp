#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 1000000LL;

lli N,
    A[MAX_SIZE + 5LL];
lli answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        if (A[i] % 7LL == 0LL or A[i] % 13LL == 0LL)
            ++answer;
    }
    cout << answer << '\n';
    
    return 0;
}
