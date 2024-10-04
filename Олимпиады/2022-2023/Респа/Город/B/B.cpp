#include <iostream>
using namespace std;

typedef long long int lli;

lli s,
    p,
    _s_,
    _p_,
    ds,
    dp,
    d;
lli answer;

int main() {
    cin >> s >> p;

    for (lli a = 1LL; a <= s; ++a) {
        _s_ = a;
        _p_ = a;

        for (lli b = 1LL; (_s_ + b <= s) and (_p_ * b <= p); ++b) {
            _s_ += b;
            _p_ *= b;

            for (lli c = 1LL; (_s_ + c <= s) and (_p_ * c <= p); ++c) {
                _s_ += c;
                _p_ *= c;

                ds = s - _s_;
                dp = p / _p_;
                d = min(ds, dp);

                if (d) answer += d;

                _s_ -= c;
                _p_ /= c;
            }

            _s_ -= b;
            _p_ /= b;
        }
    }
    
    cout << answer << '\n';
    return 0;
}
