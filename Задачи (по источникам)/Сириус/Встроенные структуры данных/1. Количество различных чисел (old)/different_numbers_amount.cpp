#include <iostream>
#include <set>
using namespace std;

int N,
    tmp;
set<int> numbers;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        numbers.insert(tmp);
    }

    cout << numbers.size() << '\n';
    return 0;
}
