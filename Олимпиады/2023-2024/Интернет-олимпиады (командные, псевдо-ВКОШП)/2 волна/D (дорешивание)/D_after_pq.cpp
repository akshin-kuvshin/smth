// author: Danila "akshin_" Aksionov

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                    pair<lli, lli>
#define ppllilli                pair<plli, lli>
#define mp(_first, _second)     make_pair(_first, _second)
#define pb(_elem)               push_back(_elem)

#define l                       first.first
#define r                       first.second
#define ind                     second

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N;
ppllilli A[MAX_SIZE];
lli index;

class Compare {
public:
    bool operator ()(const ppllilli &x, const ppllilli &y) const {
        if ((x.l == y.l) and (x.r == y.r))
            return x.ind > y.ind;
        if (x.r == y.r)
            return x.l > y.l;
        return x.r > y.r;
    }
};
priority_queue<ppllilli, vector<ppllilli>, Compare> q;

lli places[MAX_SIZE];

void solve();
bool cmp(const ppllilli&, const ppllilli&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i].l >> A[i].r;
        --A[i].l, --A[i].r;
        A[i].ind = (lli)i;
    }
    sort(A, A + N, cmp);

    index = 0LL;
    for (lli place = 0LL; place < N; ++place) {
        while ((index < N) and (A[index].l == place)) {
            q.push(A[index]);
            ++index;
        }

        // Изначально забыл добавить проверку на то, есть ли вообще элементы в куче, перед тем, как доставать их оттуда...
        if (q.empty()) {
            cout << "NO\n";
            return;
        }
        
        ppllilli cur = q.top();
        q.pop();

        if (place > cur.r) {
            cout << "NO\n";
            return;
        }

        places[place] = cur.ind;
    }

    cout << "YES\n";
    for (int i = 0; i < (int)N; ++i)
        cout << (places[i] + 1LL) << ' ';
    cout << '\n';
    return;
}

bool cmp(const ppllilli &x, const ppllilli &y) {
    return x.l <= y.l;
}
