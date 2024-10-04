// Решение заслуживает 10^6 матерных слов,
// но оно прошло все тесты и мне абсолютно похуй)

#include <iostream>
#include <algorithm>
using namespace std;

const int L_max = 1e6,
          N_max = 1e4,
          M_max = 1e5;

int length,
    socks_number,
    socks[N_max + 5][2],
    l,
    r,
    dots_number,
    dots[M_max + 5],
    dots_set[M_max + 5],
    top = 1,
    dots_height[L_max + 5];
bool used[N_max + 5];

void put_new_sock(int, int);

int main() {
    cin >> length >> socks_number >> dots_number;
    for (int i = 1; i <= socks_number; ++i)
        cin >> socks[i][0] >> socks[i][1];
    for (int i = 1; i <= dots_number; ++i) {
        cin >> dots[i];
        if (!used[dots[i]]) {
            dots_set[top++] = dots[i];
            used[dots[i]] = true;
        }
    }
    sort(dots_set + 1, dots_set + top);

    for (int i = 1; i <= socks_number; ++i)
        put_new_sock(socks[i][0], socks[i][1]);

    for (int i = 1; i <= dots_number; ++i)
        cout << dots_height[dots[i]] << '\n';
    return 0;
}

void put_new_sock(int begin, int end) {
    for (int i = 1; i <= top; ++i)
        if ( (begin <= dots_set[i]) and (dots_set[i] <= end) )
            ++dots_height[dots_set[i]];
    return;
}
