#include <iostream>
#include <set>
using namespace std;

const int MAX_SIZE = 1e5;

int N,
    M,
    tmp;
set<int> A,
         B;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        A.insert(tmp);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> tmp;
        B.insert(tmp);
    }
    
    if (A == B)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}
