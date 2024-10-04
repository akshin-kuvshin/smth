// author: Danila "akshin_" Aksionov

#include <iostream>
#define UP 0LL
#define RIGHT 1LL
#define DOWN 2LL
#define LEFT 3LL
#define x first
#define y second
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> Point;

const lli N_max = 1000LL;

lli N;
char A[N_max + 5LL][N_max + 5LL];
Point ship;
lli direction;
bool used[N_max + 5LL][N_max + 5LL][4LL];
string answers[] = {"OUT MINUS_Y", "OUT PLUS_X", "OUT PLUS_Y", "OUT MINUS_X"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        for (int j = 0; j < (int)N; ++j) {
            cin >> A[i][j];
            if (A[i][j] == 'I')
                ship = make_pair(i, j);
        }
    }

    while (0LL <= ship.x and ship.x < N and 0LL <= ship.y and ship.y < N) {
        if (used[ship.x][ship.y][direction]) {
            cout << "LOOP\n";
            return 0;
        }

        used[ship.x][ship.y][direction] = true;
        if (direction == UP)
            --ship.x;
        else if (direction == RIGHT)
            ++ship.y;
        else if (direction == DOWN)
            ++ship.x;
        else // direction == LEFT
            --ship.y;
        if (A[ship.x][ship.y] == 'X') {
            ++direction; direction %= 4LL;
        }
    }
    
    cout << answers[direction] << '\n';
    return 0;
}
