// P.S.: писал после конца контеста. Падает на примерах, хотя на примерах выдаёт
// тот же ответ, что и программы из editorial'а. Странно(

#include <iostream>
using namespace std;

const int N_max = 300,
          small = -1e9 - 1,
          big = 1e9 + 1;

int N,
    diff[N_max + 5][N_max + 5];
int A[N_max + 5];

bool check(int ind) {
    int _min = big,
        _max = small;
    
    for (int i = ind; i < N; ++i) {
        _min = min(_min, A[i]);
        _max = max(_max, A[i]);

        if (_max - _min != diff[ind][i])
            return false;
    }

    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = i; j < N; ++j)
            cin >> diff[i][j];
    
    A[N - 1] = 0;
    for (int i = N - 2; 0 <= i; --i) {
        A[i] = A[i + 1] + diff[i][i + 1];
        if (!check(i))
            A[i] = A[i + 1] - diff[i][i + 1];
    }

    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
    return 0;
}
