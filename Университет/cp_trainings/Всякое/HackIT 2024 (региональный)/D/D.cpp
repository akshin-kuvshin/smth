// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

struct wick {
    lli len;
    bool begin;
    bool end;
};

const lli INF = (lli)1e18 + 1LL;

bool flag = false;

void solve();
void f(vector<wick> a, lli cur_t, lli t);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli a, b, c, t;
    cin >> a >> b >> c >> t;
    a <<= 10; b <<= 10; c <<= 10; t <<= 10;
    
    for (bool a_beg : {false, true})
        for (bool a_end : {false, true})
            for (bool b_beg : {false, true})
                for (bool b_end : {false, true})
                    for (bool c_beg : {false, true})
                        for (bool c_end : {false, true})
                            f({{a, a_beg, a_end}, {b, b_beg, b_end}, {c, c_beg, c_end}}, 0LL, t);

    cout << (flag ? "Yes" : "No") << '\n';
    return;
}

void f(vector<wick> a, lli cur_t, lli t) {
    if (flag)
        return;
    if (cur_t > t)
        return;

    lli dt = INF;
    for (auto [len, begin, end] : a)
        if (begin and end)
            dt = min(dt, len >> 1);
        else if (begin or end)
            dt = min(dt, len);
    if (dt == INF)
        return;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (a[i].begin and a[i].end)
            a[i].len -= dt << 1;
        else if (a[i].begin or a[i].end)
            a[i].len -= dt;
        if (not a[i].len)
            a.erase(a.begin() + i);
    }

    cur_t += dt;
    if (cur_t == t) {
        flag = true;
        return;
    }

    lli a_size = (lli)a.size();
    if (not a_size)
        return;
    if (a_size == 1LL) {
        wick w;
        w.len = a.front() /* === a[0] */ .len;
        for (bool w_beg : {false, true})
            for (bool w_end : {false, true}) {
                w.begin = w_beg;
                w.end = w_end;
                f({w}, cur_t, t);
            }
        return;
    }
    // a_size == 2LL
    vector<wick> w(2);
    w[0].len = a[0].len;
    w[1].len = a[1].len;
    for (bool w0_beg : {false, true})
        for (bool w0_end : {false, true})
            for (bool w1_beg : {false, true})
                for (bool w1_end : {false, true}) {
                    w[0].begin = w0_beg;
                    w[0].end = w0_end;
                    w[1].begin = w1_beg;
                    w[1].end = w1_end;
                    f(w, cur_t, t);
                }
    return;
}
