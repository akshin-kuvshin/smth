// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<vector<lli>> a(n, vector<lli>(n));
    unordered_map<lli, lli> cnt;
    for (int i = 0; i < (int)n; ++i)
        for (int j = 0; j < (int)n; ++j) {
            cin >> a[i][j];
            ++cnt[a[i][j]];
        }
    
    unordered_map<lli, lli> rev_cnt;
    for (auto [x, c] : cnt)
        rev_cnt[c] += x;
    
    /* for (auto [x, c] : cnt)
        cout << x << ": " << c << '\n';
    for (auto [c, _sum] : rev_cnt)
        cout << "sum(" << c << ") = " << _sum << '\n';
    return; */

    lli ind;
    bool flag = true;
    for (ind = 0LL; ind < n and flag; ++ind)
        for (int j = 0; j < (int)n; ++j)
            if (cnt[a[ind][j]] == 1LL) {
                --ind;
                flag = false;
                break;
            }
    
    unordered_map<lli, lli> op_b,
                            op_c;
    for (auto elem : a[ind]) {
        lli c = cnt[elem];

        op_b[elem] = 1LL + c;
        op_b[rev_cnt[c] - elem] = 2LL * n + 1LL - c;
        
        op_c[elem] = 2LL * n + 1LL - c;
        op_c[rev_cnt[c] - elem] = 1LL + c;

        // cout << elem << ' ' << rev_cnt[c] - elem << '\n';
    }
    // return;

    /* cout << "b\n";
    for (auto [from, to] : op_b)
        cout << from << " -> " << to << '\n';
    cout << "c\n";
    for (auto [from, to] : op_c)
        cout << from << " -> " << to << '\n';
    return; */

    bool is_b;
    flag = true;
    for (int i = 0; i < (int)n and flag; ++i)
        for (int j = 0; j < (int)n; ++j) {
            if (op_b[a[i][j]] == op_c[a[i][j]])
                continue;
            if (op_b[a[i][j]] < op_c[a[i][j]])
                is_b = true;
            else // op_b[a[i][j]] > op_c[a[i][j]]
                is_b = false;
            flag = false;
            break;
        }
    
    if (not is_b)
        swap(op_b, op_c);
    for (int i = 0; i < (int)n; ++i) {
        cout << op_b[a[i][0]];
        for (int j = 1; j < (int)n; ++j)
            cout << ' ' << op_b[a[i][j]];
        cout << '\n';
    }

    return;
}
