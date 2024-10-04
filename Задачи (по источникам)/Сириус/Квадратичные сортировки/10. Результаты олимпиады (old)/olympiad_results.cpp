#include <iostream>
using namespace std;

struct member {
    int id;
    int result;

    void in();
    void out();
};

const int N_max = 1e3;

int N;
member A[N_max + 5];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        A[i].in();

    for (int i = 0; i < N; ++i)
        for (int j = i - 1; j >= 0; --j)
            if (A[j].result == A[j + 1].result and A[j].id > A[j + 1].id)
                swap(A[j], A[j + 1]);
            else if (A[j].result < A[j + 1].result)
                swap(A[j], A[j + 1]);

    for (int i = 0; i < N; ++i)
        A[i].out();
    return 0;
}

void member::in() {
    cin >> id >> result;
}

void member::out() {
    cout << id << ' ' << result << '\n';
}
