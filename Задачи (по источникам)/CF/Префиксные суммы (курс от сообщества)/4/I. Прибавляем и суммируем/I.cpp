// author: Danila "akshin_" Aksionov

#include <iostream>
using namespace std;

// Раньше здесь было (2U << 24). гы)
const uint32_t N = (1U << 24);

uint32_t m,
         q,
         a,
         b,
         cur = 0U;
uint32_t adding,
         l,
         r;
int64_t A[N];
uint32_t p[N + 1U];
uint32_t answer;

int main() {
    cin >> m >> q >> a >> b;

    while (m--) {
        cur = cur * a + b;
        adding = (cur >> 8);
        cur = cur * a + b;
        l = (cur >> 8);
        cur = cur * a + b;
        r = (cur >> 8);
        if (l > r) swap(l, r);
        ++r;

        A[l] += (int64_t)adding;
        A[r] -= (int64_t)adding;
    }

    // d[i] = A[i] - A[i - 1]   =>   A[i] = A[i - 1] + d[i]
    // d == A (патамуштамалапамяти)
    for (int i = 1; i < (int)N; ++i)
        A[i] += A[i - 1];
    
    // p[i + 1] = p[i] + A[i]
    for (int i = 0; i < (int)N; ++i)
        p[i + 1] = p[i] + (uint32_t)A[i];
    
    while (q--) {
        cur = cur * a + b;
        l = (cur >> 8);
        cur = cur * a + b;
        r = (cur >> 8);
        if (l > r) swap(l, r);
        ++r;

        answer += p[r] - p[l];
    }
    
    cout << answer << '\n';
    return 0;
}
