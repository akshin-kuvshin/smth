// author: Danila "akshin_" Aksionov

#include <iostream>
#define EMPTY '.'
#define OBSTACLE '#'
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = 100000LL;

lli N;
char S[MAX_SIZE + 5LL];
bool answer;

lli X;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> S[i];
        if (S[i] == 'X')
            X = (lli)i;
        else if (S[i] == '?' or S[i] == '#' or S[i] == '*')
            S[i] = OBSTACLE;
    }
    
    while (X != N - 1LL) {
        if (S[N - 1LL] == OBSTACLE) {
            answer = false;
            break;
        } else if (X == 0LL) {
            S[X] = OBSTACLE;
            while (S[X] == OBSTACLE)
                ++X;
        } else if (S[X - 1LL] == EMPTY and S[X + 1LL] == EMPTY)
            break;
        else if (S[X - 1LL] == OBSTACLE and S[X + 1LL] == OBSTACLE) {
            S[X] = OBSTACLE;
            while (S[X] == OBSTACLE)
                ++X;
        } else if (S[X - 1LL] == EMPTY and S[X + 1LL] == OBSTACLE) {
            S[X] = OBSTACLE;
            while (S[X] == OBSTACLE)
                ++X;
        } else if (S[X - 1LL] == OBSTACLE and S[X + 1LL] == EMPTY) {
            S[X] = OBSTACLE;
            while (X >= 0LL and S[X] == OBSTACLE)
                --X;
            if (X < 0LL) {
                answer = false;
                break;
            }
        }
    }
    
    answer = answer and (X == N - 1LL);
    cout << (answer ? "YES" : "NO") << '\n';
    return 0;
}
