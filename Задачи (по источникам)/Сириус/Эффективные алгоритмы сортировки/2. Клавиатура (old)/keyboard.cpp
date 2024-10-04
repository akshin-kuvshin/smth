#include <iostream>
using namespace std;

const int N_max = 1e2;

int N,
    durability[N_max + 5],
    K,
    clicks_number[N_max + 5],
    tmp;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> durability[i];
    
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> tmp;
        ++clicks_number[tmp - 1];
    }

    for (int i = 0; i < N; ++i)
        if (durability[i] < clicks_number[i])
            cout << "yes\n";
        else
            cout << "no\n";

    return 0;
}
