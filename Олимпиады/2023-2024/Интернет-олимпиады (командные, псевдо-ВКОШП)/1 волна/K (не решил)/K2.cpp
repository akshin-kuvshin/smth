// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e5;

lli N;
vector<lli> G[MAX_SIZE + 5LL];
set<lli> A_thinking;
lli d;

void solve();
void dfs(lli, lli, char);

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

    dfs(1LL, -1LL, 'B');
    
    cout << d << ' ' << A_thinking.size() << '\n';
    for (auto it = A_thinking.begin(); it != A_thinking.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    return;
}

void dfs(lli vertex, lli primal, char primal_think) {
    char my_think;
    if (primal_think == 'B')
        my_think = 'A';
    else { // primal_think == 'A'
        if (1LL < (lli)G[vertex].size() - 1LL)
            my_think = 'A';
        else
            my_think = 'B';
    }

    if (my_think == 'A') A_thinking.insert(vertex);
    else ++d;
    
    for (lli n : G[vertex])
        if (n != primal)
            dfs(n, vertex, my_think);
    return;
}
