#include <iostream>
#include <map>
using namespace std;

typedef long long int lli;

const lli N_max = 100000LL;

lli N,
    A[N_max + 5LL],
    B[N_max + 5LL],
    A_sum[N_max + 5LL],
    B_sum[N_max + 5LL],
    sum_d[N_max + 5LL];
lli answer;

void input();
void solution();
void output();
lli get_answer(int);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solution();
    output();
    
    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    for (int i = 0; i < (int)N; ++i)
        cin >> B[i];
    return;
}

void solution() {
    for (int i = 0; i < N; ++i)
        A_sum[i + 1] = A_sum[i] + A[i];
    for (int d = 1; d <= 10; ++d)
        answer += get_answer(d);
    return;
}

void output() {
    cout << answer << '\n';
    return;
}

lli get_answer(int d) {
    for (int i = 0; i < (int)N; ++i) {
        B_sum[i + 1] = B_sum[i] + d * B[i];
        sum_d[i + 1] = A_sum[i + 1] - B_sum[i + 1];
    }
    
    map<lli, lli> m;
    for (int i = 0; i <= (int)N; ++i)
        ++m[sum_d[i]];
    
    lli mini_answer = 0LL;
    for (map<lli, lli>::const_iterator it = m.begin(); it != m.end(); ++it) {
        lli k = it->second;
        mini_answer += k * (k - 1LL) / 2LL;
    }
    return mini_answer;
}
