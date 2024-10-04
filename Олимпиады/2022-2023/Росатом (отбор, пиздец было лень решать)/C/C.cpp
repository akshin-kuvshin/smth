// author: Danila "akshin_" Aksionov

#include <iostream>
#include <string>
#include <set>
using namespace std;

const size_t MAX_SIZE = 8ULL;

void dfs(size_t, size_t, const string&, char*, bool*, set<string> &_set);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    getline(cin, S);

    size_t ind;
    while ((ind = S.find(' ')) != string::npos)
        S.erase(ind, 1);
    
    char A[MAX_SIZE + 5ULL];
    bool used[MAX_SIZE + 5ULL] = {false};
    set<string> _set;
    for (size_t l = 1ULL; l <= S.size(); ++l)
        for (size_t i = 0ULL; i < S.size(); ++i) {
            A[0] = S[i];
            used[i] = true;
            dfs(1ULL, l, S, A, used, _set);
            used[i] = false;
        }
    
    for (set<string>::iterator it = _set.begin(); it != _set.end(); ++it)
        cout << *it << '\n';
    return 0;
}

void dfs(size_t cur, size_t _max, const string &S, char *A, bool *used, set<string> &_set) {
    if (cur == _max) {
        string _s = "";
        for (size_t i = 0ULL; i < _max; ++i)
            _s += A[i];
        _set.insert(_s);
        return;
    }

    for (size_t i = 0ULL; i < S.size(); ++i) {
        if (used[i]) continue;

        A[cur] = S[i];
        used[i] = true;
        dfs(cur + 1ULL, _max, S, A, used, _set);
        used[i] = false;
    }

    return;
}
