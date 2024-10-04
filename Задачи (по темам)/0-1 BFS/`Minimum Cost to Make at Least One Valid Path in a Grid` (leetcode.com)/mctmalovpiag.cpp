#include <vector>
#include <deque>
using namespace std;

#define mp(_first, _second)     make_pair(_first, _second)

class Solution {
private:
    const int INF = (int)1e9 + 1;
    const vector<pair<pair<int, int>, int>> deltas = {{{-1, 0}, 4}, {{0, 1}, 1}, {{1, 0}, 3}, {{0, -1}, 2}};

public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(),
            m = grid[0].size();

        deque<pair<int, int>> q;
        vector<vector<int>> d(n, vector<int>(m, INF));

        d[0][0] = 0;
        q.push_back({0, 0});
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop_front();

            for (pair<pair<int, int>, int> delta : deltas) {
                pair<int, int> ns = {cur.first + delta.first.first, cur.second + delta.first.second};
                if (ns.first < 0 or n <= ns.first or ns.second < 0 or m <= ns.second)
                    continue;
                
                int len = (grid[cur.first][cur.second] == delta.second ? 0 : 1);
                if (d[cur.first][cur.second] + len < d[ns.first][ns.second]) {
                    d[ns.first][ns.second] = d[cur.first][cur.second] + len;
                    if (len == 0)
                        q.push_front(ns);
                    else
                        q.push_back(ns);
                }
            }
        }

        return d[n - 1][m - 1];
    }
};