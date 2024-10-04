#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 200000LL;

lli N,
    c,
    costs[MAX_SIZE + 5LL];
lli counter;
lli Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--) {
        cin >> N >> c;
        for (int i = 1; i <= N; ++i) {
            cin >> costs[i];
            costs[i] += i;
        }

        sort(costs + 1LL, costs + 1LL + N);

        counter = 0LL;
        for (int i = 1; i <= N; ++i)
            if (c >= costs[i]) {
                c -= costs[i];
                ++counter;
            } else break;
        
        cout << counter << '\n';
    }

    return 0;
}
