// author: Danila "akshin_" Aksionov

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

class Ticket {
public:
    string to;
    lli t;
    lli dt;

    Ticket(const string &_to, lli _t, lli _dt) {
        to = _to;
        t = _t;
        dt = _dt;
        return;
    }
};

lli N;
unordered_map<string, vector<Ticket>> m;
string start = "Moscow",
       finish = "Malokribirsk";
vector<string> good_way;
lli good_length = INF;
vector<string> max_way;
lli max_length;

void solve();
lli parsed(const string&);
void dfs(const string&, vector<string>&, lli, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    while (N--) {
        string from,
               to;
        lli t,
            dt;

        getline(cin, from, '|');
        if (from[0] == '\n')
            from = from.substr(1, from.size());

        getline(cin, to, '|');

        string tmp;
        getline(cin, tmp, '|');
        t = parsed(tmp);
        getline(cin, tmp);
        dt = parsed(tmp);

        m[from].pb(Ticket(to, t, dt));
    }

    vector<string> stack;
    stack.pb(start);
    for (Ticket ns : m[start]) {
        stack.pb(ns.to);
        dfs(ns.to, stack, ns.dt, (ns.t + ns.dt) % 1440LL);
        stack.pop_back();
    }
    
    int sz;
    if (!good_way.empty()) {
        sz = (int)good_way.size();

        cout << good_way[0];
        for (int i = 1; i < sz; ++i)
            cout << '|' << good_way[i];
        cout << '\n';

        lli hours = good_length / 60LL,
            minutes = good_length % 60LL;
        cout << hours << ':';
        if (minutes < 10LL)
            cout << '0';
        cout << minutes << '\n';
    } else {
        sz = (int)max_way.size();

        cout << max_way[0];
        for (int i = 1; i < sz; ++i)
            cout << '|' << max_way[i];
        cout << '\n';

        lli hours = max_length / 60LL,
            minutes = max_length % 60LL;
        cout << hours << ':';
        if (minutes < 10LL)
            cout << '0';
        cout << minutes << '\n';
    }

    return;
}

lli parsed(const string &S) {
    int ind = -1,
        sz = (int)S.size();
    for (int i = 0; i < sz; ++i)
        if (S[i] == ':') {
            ind = i;
            break;
        }
    
    lli hours = 0LL;
    for (int i = 0; i < ind; ++i)
        hours = 10LL * hours + S[i] - '0';
    lli minutes = 0LL;
    for (int i = ind + 1; i < sz; ++i)
        minutes = 10LL * minutes + S[i] - '0';
    return 60LL * hours + minutes;
}

void dfs(const string &v, vector<string> &stack, lli length, lli cur_time) {
    if (stack.back() == finish) {
        if (length < good_length) {
            good_way = stack;
            good_length = length;
        }
        return;
    }
    if (max_way.size() < stack.size()) {
        max_way = stack;
        max_length = length;
    }

    for (Ticket ns : m[v]) {
        lli waiting = ns.t - cur_time;
        if (waiting < 0LL)
            waiting += 1440LL;
        if (waiting < 90LL or 720LL <= waiting)
            continue;
        
        stack.pb(ns.to);
        dfs(ns.to, stack, (length + waiting + ns.dt) % 1440LL, (cur_time + waiting + ns.dt) % 1440LL);
        stack.pop_back();
    }

    return;
}
