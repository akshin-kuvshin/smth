#include <iostream>
#include <set>
#include <string>
using namespace std;

string S;
int sz;
set<char> used;

int main() {
    getline(cin, S);

    sz = S.size();
    for (int i = 0; i < sz; ++i)
        if (used.find(S[i]) == used.end()) { // символ встречается впервые
            used.insert(S[i]);
            cout << S[i];
        }
    cout << '\n';
    return 0;
}
