#include <iostream>
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 2000LL;

lli N;
char s[MAX_SIZE + 5LL];
lli l;
lli Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> s[i];
        
        l = N;
        for (int i = 0, j = (int)N - 1; i < j; ++i, --j)
            if (s[i] != s[j]) l -= 2LL;
            else break;

        cout << l << '\n';
    }

    return 0;
}
