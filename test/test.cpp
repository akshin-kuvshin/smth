#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> S;
    S.insert(1); S.insert(5);
    cout << S.contains(1) << '\n' << S.contains(12) << '\n';
    return 0;
}
