#include <iostream>
#define _first make_pair(true, false)
#define _second make_pair(false, true)
#define _both make_pair(true, true)
using namespace std;

long long x,
          Cx,
          i,
          Ai,
          j,
          Bj;

void update(pair<bool, bool>);

int main() {
    cin >> x;

    i = j = 1;
    update(_both);
    for (int k = 0; k < x; ++k) {
        if (Ai < Bj) {
            Cx = Ai;

            ++i;
            update(_first);
        } else if (Ai == Bj) {
            Cx = Ai;

            ++i;
            ++j;
            update(_both);
        } else { // Ai > Bj
            Cx = Bj;

            ++j;
            update(_second);
        }
    }

    cout << Cx << '\n';
    return 0;
}

void update(pair<bool, bool> flags) {
    if (flags.first)
        Ai = i * i;
    if (flags.second)
        Bj = j * j * j;
    return;
}
