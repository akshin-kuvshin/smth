// author: Danila "akshin_" Aksionov

#include <iostream>
#include <map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli N; // N % 2LL == 0LL
map<lli, lli> m;

void solve();
void factorize(lli, map<lli, lli>&);
bool is_single(map<lli, lli>&);
lli _pow(lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;

    if (N % 4LL != 0LL) {
        cout << "prime\n";
        return;
    }

    factorize(N, m);

    if (is_single(m)) {
        cout << "single\n";
        while (N % 4LL == 0LL) {
            cout << "2 ";
            N /= 2LL;
        }
        cout << N << '\n';
        return;
    }
    
    map<lli, lli>::iterator it = m.begin();
    lli two = it->second;
    ++it;
    lli a = it->first,
        b = _pow(it->first, it->second - 1LL);
    ++it;
    while (it != m.end()) {
        b *= _pow(it->first, it->second);
        ++it;
    }

    cout << "many\n";
    for (int i = 0; i + 1 < (lli)two; ++i)
        cout << "2 ";
    cout << (2LL * a * b) << '\n';
    for (int i = 0; i + 2 < (lli)two; ++i)
        cout << "2 ";
    cout << (2LL * a) << ' ' << (2LL * b) << '\n';

    return;
}

void factorize(lli num, map<lli, lli> &divs) {
    for (lli d = 2LL; d * d <= num; ++d)
        while (num % d == 0LL) {
            num /= d;
            ++divs[d];
        }
    if (num > 1LL)
        ++divs[num];
    return;
}

bool is_single(map<lli, lli> &divs) {
    lli cnt = 0LL;
    for (plli p : divs) {
        if (p.first == 2LL)
            continue;
        cnt += p.second;
    }
    return (cnt <= 1LL);
}

lli _pow(lli base, lli ptr) {
    if (ptr == 0LL)
        return 1LL;
    if (ptr % 2LL == 0LL) {
        lli half = _pow(base, ptr / 2LL);
        return half * half;
    }
    return base * _pow(base, ptr - 1LL);
}
