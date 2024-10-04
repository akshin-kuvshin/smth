#include <iostream>
#include <set>
#define set_int_it set<int>::iterator
using namespace std;

const int MAX_SETS_NUMBER = 100,
          MAX_SET_POWER = 1e5;

int sets_number,
    sizes[MAX_SETS_NUMBER + 5],
    sets[MAX_SETS_NUMBER + 5][MAX_SET_POWER + 5];

int _union_power;
set<int> _union;

int main() {
    // Input
    cin >> sets_number;
    for (int i = 0; i < sets_number; ++i) {
        cin >> sizes[i];
        for (int j = 0; j < sizes[i]; ++j)
            cin >> sets[i][j];
    }

    // Solution
    for (int i = 0; i < sets_number; ++i)
        for (int j = 0; j < sizes[i]; ++j)
            _union.insert(sets[i][j]);
    
    _union_power = _union.size();

    // Output
    cout << _union_power << '\n';
    for (set_int_it it = _union.begin(); it != _union.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
    
    return 0;
}
