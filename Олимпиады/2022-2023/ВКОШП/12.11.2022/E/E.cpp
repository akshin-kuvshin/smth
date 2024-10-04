#include <iostream>
#include <string>
#define word 0
#define symbol 1
using namespace std;

const int N_max = 1e5,
          MAX_FULL_SIZE = 1e6;

int words_amount,
    requests_amount,
    requests[5 * N_max + 5];
int A[MAX_FULL_SIZE + 5][2],
    top = 1;
string S[N_max + 5];

int main() {
    cin >> words_amount >> requests_amount;

    for (int i = 0; i < words_amount; ++i)
        cin >> S[i];
    for (int i = 0; i < requests_amount; ++i)
        cin >> requests[i];

    int sz;
    for (int i = 0; i < words_amount; ++i) {
        sz = S[i].size();
        for (int j = 0; j < sz; ++j) {
            A[top][word] = i + 1;
            A[top][symbol] = j + 1;
            ++top;
        }
    }

    for (int i = 0; i < requests_amount; ++i)
        cout << A[requests[i]][word] << ' ' << A[requests[i]][symbol] << '\n';

    return 0;
}
