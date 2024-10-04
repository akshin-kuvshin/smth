#include <iostream>
#define x first
#define y second
using namespace std;

const int MAX_SIZE = 1e3;

int N,
    M,
    time;
pair<int, int> start,
               finish;
char table[MAX_SIZE + 5][MAX_SIZE + 5];

bool used[MAX_SIZE + 5][MAX_SIZE + 5];
bool flag;

// TODO: доделать ДФС
void dfs(pair<int, int>);

int main() {
    cin >> N >> M;
    cin >> start.x >> start.y;
    cin >> finish.x >> finish.y;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> table[i][j];
    
    used[start.x][start.y] = true;
    dfs(start);
    used[start.x][start.y] = false;

    if (flag)
        cout << time << '\n';
    else
        cout << -1 << '\n';
    return 0;
}
