#include <iostream>
using namespace std;

typedef long long int lli;

lli A,
    B,
    C;
lli answer;

int main() {
    cin >> A >> B >> C;
    answer = min(A + B, C);
    cout << answer << '\n';    
    return 0;
}
