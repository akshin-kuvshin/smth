#include <iostream>
#include <array>
#include <algorithm>
#define data first
#define index second
using namespace std;

using lli = long long int;

const int N_max = 1e6;

int N;
array<lli, N_max + 5> A;
array<pair<lli, int>, N_max + 5> B;
int l,
    r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        B[i + 1] = make_pair(B[i].data + A[i], i + 1);
    }

    /* for (int i = 0; i <= N; ++i)
        cout << B[i].data << ' ';
    cout << '\n';
    return 0; */

    sort(B.begin(), B.begin() + N + 1);

    int i = 0;
    while (i < N) {
        if (B[i].data == B[i + 1].data) {
            int j = i + 2;
            while (j <= N and B[i].data == B[j].data)
                ++j;
            --j;

            if (B[j].index - B[i].index > r - l) {
                l = B[i].index;
                r = B[j].index;
            }

            i = j + 1;
        } else ++i;
    }

    if (!l and !r)
        cout << -1 << '\n';
    else {
        ++l;
        cout << l << ' ' << r << '\n';   
    }

    return 0;
}
