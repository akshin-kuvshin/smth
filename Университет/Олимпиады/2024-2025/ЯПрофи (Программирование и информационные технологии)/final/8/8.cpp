// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

lli _pow(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli n;
    cin >> n;

    vector<lli> cnt(10);
    if (n == 1000000000000000000LL) {
        ++cnt[1];
        cnt[0] += 18LL;
        --n;
    }
    for (lli pos = 0LL; pos <= 18LL; ++pos) {
        for (lli d = 1LL; d <= 9LL; ++d) {
            lli start = d * _pow(10LL, pos),
                step = _pow(10LL, pos + 1LL);
            if (start > n)
                break;
            lli k = n / step + 1LL;
            cnt[d] += (k - 1LL) * _pow(10LL, pos);
            start += (k - 1LL) * step;
            if (start > n)
                continue;
            cnt[d] += min(n - start + 1LL, _pow(10LL, pos));
        }

        if (pos == 18LL)
            continue;
        lli start = _pow(10LL, pos + 1LL);
        lli step = start;
        if (start > n)
            continue;
        lli k = n / step;
        cnt[0] += (k - 1LL) * _pow(10LL, pos);
        start += (k - 1LL) * step;
        if (start > n)
            continue;
        cnt[0] += min(n - start + 1LL, _pow(10LL, pos));
    }

    for (auto amount : cnt)
        cout << amount << ' ';
    cout << '\n';    
    return 0;
}

lli _pow(lli base, lli ptr) {
    if (not ptr)
        return 1LL;
    return base * _pow(base, ptr - 1LL);
}
