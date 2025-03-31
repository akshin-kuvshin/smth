// author: Danila "akshin_" Axyonov

#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

#define NO_DISEASE          -1LL

const lli INF = (lli)1e18 + 1LL;

struct handshake {
    lli t;
    lli u;
    lli v;
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    
    solve();
    
    return 0;
}

void solve() {
    ifstream cin("tracing.in");
    cin.tie(nullptr);
    ofstream cout("tracing.out");

    lli n,
        m;
    cin >> n >> m;
    vector<bool> d(n);
    for (int i = 0; i < (int)n; ++i) {
        char flag;
        cin >> flag;
        d[i] = (flag == '1');
    }
    vector<handshake> h(m);
    for (int i = 0; i < (int)m; ++i) {
        cin >> h[i].t >> h[i].u >> h[i].v;
        --h[i].u;
        --h[i].v;
    }
    sort(h.begin(), h.end(), [](handshake h1, handshake h2) {
        return h1.t < h2.t;
    });



    unordered_set<int> possible_zero_patients;
    lli y = INF,
        z = -1LL;
    for (int i = 0; i < (int)n; ++i) {
        for (lli k = 0LL; k <= m; ++k) {
            vector<lli> d_flag(n, NO_DISEASE);
            d_flag[i] = k;

            for (auto [_, u, v] : h) {
                if (d_flag[u] == NO_DISEASE and d_flag[v] != NO_DISEASE) {
                    if (d_flag[v] > 0LL) {
                        d_flag[u] = k;
                        --d_flag[v];
                    }
                } else if (d_flag[u] != NO_DISEASE and d_flag[v] == NO_DISEASE) {
                    if (d_flag[u] > 0LL) {
                        --d_flag[u];
                        d_flag[v] = k;
                    }
                } else if (d_flag[u] != NO_DISEASE and d_flag[v] != NO_DISEASE) {
                    d_flag[u] = max(d_flag[u] - 1LL, 0LL);
                    d_flag[v] = max(d_flag[v] - 1LL, 0LL);
                }
            }

            bool equal = true;
            for (int j = 0; j < (int)n; ++j)
                if (d[j] != (d_flag[j] != NO_DISEASE)) {
                    equal = false;
                    break;
                }
            
            if (equal) {
                possible_zero_patients.insert(i);
                y = min(y, k);
                z = max(z, k);
            }
        }
    }


    
    cout << possible_zero_patients.size() << ' ' << y << ' ';
    if (z < m)
        cout << z;
    else // z == m
        cout << "Infinity";
    cout << '\n';

    cin.close();
    cout.close();
    return;
}
