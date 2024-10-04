#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

const lli B = 0LL,
          S = 1LL,
          C = 2LL;

string input;
lli _B,
    _S,
    _C,
    n[3],
    p[3],
    _r;
lli answer;

bool f(lli);
lli bs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;
    cin >> n[B] >> n[S] >> n[C];
    cin >> p[B] >> p[S] >> p[C];
    cin >> _r;

    for (char c : input) {
        if (c == 'B') ++_B;
        else if (c == 'S') ++_S;
        else ++_C;
    }

    answer = bs();
    cout << answer << '\n';
    return 0;
}

bool f(lli x) {
    lli money_req = 0LL; // money_required
    money_req += max(0LL, p[B] * (x * _B - n[B]));
    money_req += max(0LL, p[S] * (x * _S - n[S]));
    money_req += max(0LL, p[C] * (x * _C - n[C]));
    return (money_req <= _r);
}

lli bs() {
    lli l = 0LL,
        r = (lli)1e15;
    
    while (l + 1LL < r) {
        lli m = (l + r) / 2LL;

        if (f(m))
            l = m;
        else
            r = m;
    }

    return l;
}
