// authors: Danila "akshin_" Axyonov & Stepan Evseev

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define mp(_first, _second)     make_pair(_first, _second)
#define pb(_elem)               push_back(_elem)

const lli INF = (lli)1e18 + 1LL,
          NOT_DEFINED = -1LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli Q;
    cin >> Q;
    while (Q--)
        solve();

    return 0;
}

void solve() {
    vector<pair<char, lli>> a(3);
    for (auto& p : a)
        cin >> p.first >> p.second;
    sort(a.begin(), a.end());

    bool flag = false;
    if (a.front().first != a.back().first) {
        flag = true;
        if (a[0].first == a[1].first) {
            a[0].first = a[1].first = a[2].first;
            --a[0].second;
            --a[1].second;
        }
        else { // a[1].first == a[2].first
            a[1].first = a[2].first = a[0].first;
            --a[1].second;
            --a[2].second;
        }
    }

    lli zeros = 0LL;
    for (auto p : a)
        if (p.second == 0LL)
            ++zeros;

    if (zeros == 2LL) {
        cout << "1\n";
        return;
    }
    if (zeros == 1LL) {
        lli m = INF;
        for (auto p : a) {
            if (p.second == 0LL)
                continue;
            m = min(m, p.second);
        }
        cout << ((m % 2LL == 0LL) ? 1 : 0) << '\n';
        return;
    }
    // zeros == 0LL

    lli odd = 0LL,
        even = 0LL;
    for (auto p : a)
        if (p.second % 2LL == 0LL)
            ++even;
        else // p.second % 2LL == 1LL
            ++odd;

    if (odd >= 2LL)
        cout << (1LL - (lli)flag) << '\n';
    else if (even == 3LL)
        cout << (lli)flag << '\n';
    else { // odd == 1LL and even == 2LL
        lli n = NOT_DEFINED,
            m = NOT_DEFINED,
            k = NOT_DEFINED;
        for (auto p : a)
            if (p.second % 2LL == 0LL) {
                if (m == NOT_DEFINED)
                    m = p.second / 2LL;
                else // m != NOT_DEFINED
                    k = p.second / 2LL;
            } else // p.second % 2LL == 1LL
                n = p.second / 2LL;

        if (n < m + k) {
            cout << (1LL - (lli)flag) << '\n';
            return;
        }

        if (m > k)
            swap(m, k);
        lli d = min(n, m);
        n -= d;
        m -= d;
        if (m != 0LL) {
            m = 0LL; // unnecessary
            k -= m;
        }
        if (n < k)
            cout << (1LL - (lli)flag) << '\n';
        else // n >= k
            cout << (lli)flag << '\n';
    }

    return;
}

