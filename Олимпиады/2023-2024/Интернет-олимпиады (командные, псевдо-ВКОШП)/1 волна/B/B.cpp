// author: Danila "akshin_" Aksionov

// 42
#include <iostream>
using namespace std;
typedef long long int lli;

void solve();
lli gcd_R(lli, lli);
lli lcm(lli, lli);
lli lcm_N(lli);

lli max_ans,
    K,
    lcm_K,
    answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> max_ans >> K;
    --max_ans;

    if (K > 42LL)
        answer = 0LL;
    else {
        lcm_K = lcm_N(K);
        if (max_ans / lcm_K == 0LL)
            answer = 0LL;
        else
            answer = lcm_K * (max_ans / lcm_K);
    }
    
    cout << (answer + 1LL) << '\n';
    return;
}

lli gcd_R(lli a, lli b) {
    return ((a && b) ? gcd_R(b, a % b) : (a | b));
}

lli lcm(lli a, lli b) {
    return a / gcd_R(a, b) * b;
}

lli lcm_N(lli N) {
    lli result = 1LL;
    for (lli num = 2LL; num <= N; ++num)
        result = lcm(result, num);
    return result;
}
