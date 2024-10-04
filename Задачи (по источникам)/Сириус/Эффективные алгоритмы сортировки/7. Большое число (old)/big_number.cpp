#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N_max = 1e2;

int N;
string A[N_max + 5];

bool comp(const string&, const string&);

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    sort(A, A + N, comp);

    for (int i = 0; i < N; ++i)
        cout << A[i];
    cout << '\n';
    return 0;
}

bool comp(const string &S1, const string &S2) {
    return (S1 + S2 > S2 + S1);
}
