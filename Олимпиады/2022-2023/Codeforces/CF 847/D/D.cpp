#include <iostream>
#include <set>
using namespace std;

// Variables
int t;
int N;
multiset<int> A;
int answer;

// Functions
void input();
void solution();
void output();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while (t--) {
        input();
        solution();
        output();
    }
    return 0;
}

void input() {
    A.clear();

    cin >> N;

    int tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        A.insert(tmp);
    }
    
    return;
}

void solution() {
    answer = 0;

    while (!A.empty()) {
        int start = *A.begin();
        A.erase(A.begin());

        set<int>::iterator it;
        while ((it = A.find(++start)) != A.end()) A.erase(it);

        ++answer;
    }
    
    return;
}

void output() {
    cout << answer << '\n';    
    return;
}
