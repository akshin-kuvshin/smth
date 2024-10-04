#include <iostream>
using namespace std;

// Constants
const int Nmax = 10;

// Variables
int N,
    chips[Nmax + 5];

// Functions
void setChip(int);
void setChips(int, int);
void deleteChip(int);

int main() {
    cin >> N;
    setChips(1, N);

    return 0;
}

void setChip(int setting) {
    if (setting == 1)
        cout << setting << ' ';
    else {
        setChip(setting - 1);
        cout << setting << ' ';
        deleteChip(setting - 1);
    }

    return;
}

void setChips(int from, int to) {
    if ( ( (from == 1) and (to == 1) ) or (to == 0) )
        cout << from << '\n';
    else if (from == to - 1)
        if (from == 1)
            cout << from << ' ' << to << ' ';
        else {
            cout << from << ' ';
            deleteChip(from - 1);
            cout << to << ' ';
            setChips(1, to - 2);
        }
    else if (from == 1) {
        cout << from << ' ';
        setChips(from + 1, to);
    } else {
        cout << from << ' ';
        deleteChip(from - 1);
        setChips(from + 1, to);
    }

    return;
}

void deleteChip(int deleting) {
    if (deleting == 1)
        cout << -deleting << ' ';
    else {
        setChip(deleting - 1);
        cout << -deleting << ' ';
        deleteChip(deleting - 1);
    }

    return;
}
