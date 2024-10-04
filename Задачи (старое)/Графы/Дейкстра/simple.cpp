// author: Danila "akshin_" Aksionov

#include <iostream>
#include <vector>
#include <algorithm>
#define vertex first
#define length second
#define NONE -1LL
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 105LL,
          BIG = (lli)1e6;

lli N;
vector<pair<lli, lli>> G[MAX_SIZE];
lli S,
    F;
lli d[MAX_SIZE];
bool used[MAX_SIZE];
lli answer;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> S >> F;
    fill(d, d + N + 1LL, BIG);

    lli tmp_length;
    for (int i = 1; i <= (int)N; ++i)
        for (int j = 1; j <= (int)N; ++j) {
            cin >> tmp_length;
            if (tmp_length > 0LL)
                G[i].push_back(make_pair(j, tmp_length));
        }
    


    d[S] = 0LL;
    while (true) {
        // Ищем вершину с минимальным d
        lli current = NONE,
            current_d = BIG;
        for (int i = 1; i <= (int)N; ++i)
            if (!used[i] and (d[i] < current_d)) {
                current = i;
                current_d = d[i];
            }
        if (current == F) {
            answer = current_d;
            break;
        } else if (current == NONE) {
            answer = NONE;
            break;
        }

        for (pair<lli, lli> neighbour : G[current])
            if (!used[neighbour.vertex])
                d[neighbour.vertex] = min(d[neighbour.vertex], current_d + neighbour.length);
        
        used[current] = true;
    }

    cout << answer << '\n';
    
    return;
}
