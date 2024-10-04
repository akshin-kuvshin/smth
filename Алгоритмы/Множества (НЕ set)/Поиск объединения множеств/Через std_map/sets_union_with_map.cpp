#include <iostream>
#include <map>
using namespace std;

const int MAX_SETS_NUMBER = 100,
          MAX_SET_POWER = 1e5;

int sets_number,
    sizes[MAX_SETS_NUMBER + 5],
    sets[MAX_SETS_NUMBER + 5][MAX_SET_POWER + 5];

// used[elem] == false     - wasn't included in _union
// used[elem] == true      - was included in _union
map<int, bool> used;

int _union_power,
    _union[MAX_SETS_NUMBER * MAX_SET_POWER + 5];

int main() {
    // Input
    cin >> sets_number;
    for (int i = 0; i < sets_number; ++i) {
        cin >> sizes[i];
        for (int j = 0; j < sizes[i]; ++j) {
            int tmp;
            cin >> tmp;

            used[tmp] = false;
            sets[i][j] = tmp;
        }
    }

    // Solution
    for (int i = 0; i < sets_number; ++i)
        for (int j = 0; j < sizes[i]; ++j) {
            int elem = sets[i][j];

            if (!used[elem]) {
                _union[_union_power++] = elem;
                used[elem] = true;
            }
        }

    // Output
    cout << _union_power << '\n';
    for (int i = 0; i < _union_power; ++i)
        cout << _union[i] << ' ';
    cout << '\n';

    return 0;
}
