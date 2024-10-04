// author: Danila "akshin_" Aksionov
 
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;
 
const lli MAX_SIZE = (lli)1e5;
 
lli N;
vector<lli> G[MAX_SIZE + 5LL];
set<lli> A_thinking_1;
lli d_from_A;
set<lli> A_thinking_2;
lli d_from_B;
 
void solve();
void dfs_from_A(lli, lli, char);
void dfs_from_B(lli, lli, char);
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    solve();
     
    return 0;
}
 
void solve() {
    cin >> N;
    for (int _ = 0; _ + 1 < (int)N; ++_) {
        lli a,
            b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    dfs_from_A(1LL, -1LL, 'B');
    dfs_from_B(1LL, -1LL, 'A');
     
    if (d_from_A > d_from_B) {
        cout << d_from_A << ' ' << A_thinking_1.size() << '\n';
        for (auto it = A_thinking_1.begin(); it != A_thinking_1.end(); ++it)
            cout << *it << ' ';
    } else {
        cout << d_from_B << ' ' << A_thinking_2.size() << '\n';
        for (auto it = A_thinking_2.begin(); it != A_thinking_2.end(); ++it)
            cout << *it << ' ';
    }
    cout << '\n';
 
    return;
}
 
void dfs_from_A(lli vertex, lli primal, char primal_think) {
    char my_think = ((primal_think == 'B') ? 'A' : 'B');
    if (my_think == 'A') A_thinking_1.insert(vertex);
    else ++d_from_A;
     
    for (lli n : G[vertex])
        if (n != primal)
            dfs_from_A(n, vertex, my_think);
    return;
}
 
void dfs_from_B(lli vertex, lli primal, char primal_think) {
    char my_think = ((primal_think == 'B') ? 'A' : 'B');
    if (my_think == 'A') A_thinking_2.insert(vertex);
    else if (primal != -1LL) ++d_from_B;
 
    for (lli n : G[vertex])
        if (n != primal)
            dfs_from_B(n, vertex, my_think);
    return;
}