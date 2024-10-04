#include <iostream>
using namespace std;
typedef long long int lli;

const lli round[] = {1LL, 0LL, 0LL, 0LL, 0LL, 0LL, 1LL, 0LL, 2LL, 1LL};

lli N;ôû
lli answer;

int main() {
    cin >> N;

    while (N) {
        answer += round;
        N /= 10LL;
    }

    cout << answer << '\n';
    return 0;
}