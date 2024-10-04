#include <iostream>
#include <queue>
#define END -1LL
using namespace std;

typedef long long int lli;

struct Node {
    lli region;
    lli b1;
    lli b2;
};

const lli N_max = 16LL;

lli N,
    A[N_max + 5LL],
    _sum,
    father;
Node current;
queue<Node> q;

// Functions
void input();
void solution();
void output();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
    output();
    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> A[i];
        _sum += A[i];
    }   
    return;
}

void solution() {
    father = _sum;
    
    q.push({N - 1LL, 0LL, 0LL});
    while (!q.empty()) {
        current = q.front();
        q.pop();

        if (current.region == END) {
            if (current.b1 == current.b2)
                father = min(father, _sum - current.b1 - current.b2);
            continue;
        }

        q.push({current.region - 1LL, current.b1, current.b2});
        q.push({current.region - 1LL, current.b1 + A[current.region], current.b2});
        q.push({current.region - 1LL, current.b1, current.b2 + A[current.region]});
    }

    return;
}

void output() {
    cout << father << '\n';    
    return;
}
