#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

const lli N_max = 200000LL;

lli N,
    A[N_max + 5LL];
lli negatives_number;
lli _sum;
lli Q;

bool comp(lli, lli);
lli _abs(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--) {
        negatives_number = 0LL;

        cin >> N;
        for (int i = 0; i < (int)N; ++i) {
            cin >> A[i];
            if (A[i] < 0LL)
                ++negatives_number;
        }
        
        sort(A, A + N, comp);

        _sum = 0LL;
        if (negatives_number % 2LL == 0LL)
            _sum += _abs(A[0]);
        else // нечётное кол-во отрицательных
            _sum -= _abs(A[0]);
        for (int i = 1; i < (int)N; ++i)
            _sum += _abs(A[i]);

        cout << _sum << '\n';
    }
    
    return 0;
}

bool comp(lli num1, lli num2) {
    return _abs(num1) < _abs(num2);
}

lli _abs(lli num) {
    if (num < 0LL)
        return -num;
    return num;
}
