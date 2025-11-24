// author: Danila "akshin_" Axyonov

// я смог, но почему-то не чувствую себя от этого счастливым

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define d                   first
#define a                   second

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
    lli n,
        m,
        q;
    cin >> n >> m >> q;
    vector<plli> tasks(n);
    for (int i = 0; i < (int)n; ++i)
        cin >> tasks[i].a;
    for (int i = 0; i < (int)n; ++i)
        cin >> tasks[i].d;
    vector<lli> movies(m);
    for (int i = 0; i < (int)m; ++i)
        cin >> movies[i];
    
    sort(tasks.begin(), tasks.end());
    vector<lli> pref_t(n),
                free_time(n);
    pref_t[0] = tasks[0].a;
    free_time[0] = tasks[0].d - pref_t[0];
    for (int i = 1; i < (int)n; ++i) {
        pref_t[i] = pref_t[i - 1] + tasks[i].a;
        free_time[i] = tasks[i].d - pref_t[i];
    }
    for (int i = (int)n - 2; i >= 0; --i)
        free_time[i] = min(free_time[i], free_time[i + 1]);

    vector<lli> pref_m(m);
    pref_m[0] = movies[0];
    for (int i = 1; i < (int)m; ++i)
        pref_m[i] = pref_m[i - 1] + movies[i];
    
    while (q--) {
        lli time;
        cin >> time;

        lli r = (lli)(upper_bound(tasks.begin(), tasks.end(), mp(time, -1LL)) - tasks.begin());
        if (r == 0LL)
            time = min(time, free_time.front());
        else if (/*0LL < r and */ r < n) {
            if (tasks[r].d - time >= tasks[r].a)
                time = time - pref_t[r - 1LL];
            time = min(time, free_time[r]);
        } else // r == n
            time = time - pref_t.back();
        
        lli k = (lli)(upper_bound(pref_m.begin(), pref_m.end(), time) - pref_m.begin());
        cout << k << ' ';
    }
    cout << '\n';
    
    return;
}
