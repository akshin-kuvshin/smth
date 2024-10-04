#include <iostream>
using namespace std;

typedef long long int lli;

char c;
lli Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--) {
        cin >> c;
        if (c == 'c' or c == 'o' or c == 'd' or c == 'e' or c == 'f' or c == 'r' or c == 's')
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
