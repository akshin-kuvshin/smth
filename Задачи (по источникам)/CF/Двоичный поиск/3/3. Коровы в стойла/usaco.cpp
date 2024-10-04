#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 10000LL;

lli N,
    K,
    A[MAX_SIZE + 5LL];
lli answer;

lli bs();
bool f(lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    answer = bs();
    cout << answer << '\n';    
    return 0;
}

// Проверяем, можно ли расставить коров так, чтобы минимальное расстояние было хотя бы (x).
// Т.е. все расстояния между коровами должны быть хотя бы (x).
bool f(lli x) {
    lli i = 1LL,
        _k = 1LL;
    
    lli _distance = 0LL;
    while (i < N and _k < K) {
        _distance += A[i] - A[i - 1LL];

        if (_distance >= x) {
            ++_k;
            _distance = 0LL;
        }

        ++i;
    }

    return (_k == K);
}

lli bs() {
    lli l = 0LL, // можно
        r = 1000000000LL; // уже нельзя
    
    while (l + 1LL < r) {
        lli mid = (l + r) / 2LL;

        if (f(mid))
            l = mid;
        else
            r = mid;
    }

    return l;
}
