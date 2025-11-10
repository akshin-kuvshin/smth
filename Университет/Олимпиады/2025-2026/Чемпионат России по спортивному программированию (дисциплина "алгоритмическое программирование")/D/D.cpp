// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

const lli INF = (lli)1e18 + 1LL;

struct Event {
    lli x;
    lli a;
    bool begin;
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        P;
    cin >> n >> P;
    unordered_set<lli> bad_xs;
    vector<Event> events;
    while (n--) {
        lli x,
            a,
            r;
        cin >> x >> a >> r;
        bad_xs.insert(x);
        events.push_back({
            max(x - r, 0LL),
            a,
            true
        });
        events.push_back({
            min(x + r, P) + 1LL,
            a,
            false
        });
    }
    sort(events.begin(), events.end(), [](Event e1, Event e2) {
        return e1.x < e2.x;
    });

    lli m;
    cin >> m;
    multiset<plli> Bs;
    for (int i = 1; i <= (int)m; ++i) {
        lli b;
        cin >> b;
        Bs.insert(make_pair(b, (lli)i));
    }

    vector<plli> ans;
    lli x = 0LL;
    int cur_e = 0;
    multiset<lli> As;
    while (x <= P and not Bs.empty()) {
        while (cur_e < (int)events.size() and events[cur_e].x == x) {
            if (events[cur_e].begin)
                As.insert(events[cur_e].a);
            else // not events[cur_e].begin
                As.erase(As.find(events[cur_e].a));
            ++cur_e;
        }

        if (bad_xs.contains(x)) {
            ++x;
            continue;
        }

        lli a = (As.empty() ? 0LL : *(--As.end()));
        auto it = Bs.upper_bound(make_pair(a, INF));
        if (it == Bs.end()) {
            x = ((cur_e < (int)events.size()) ? events[cur_e].x : (P + 1LL));
            continue;
        }
        ans.emplace_back(it->second, x);
        Bs.erase(it);
        ++x;
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (plli& p : ans)
        cout << p.first << ' ' << p.second << '\n';
    return;
}
