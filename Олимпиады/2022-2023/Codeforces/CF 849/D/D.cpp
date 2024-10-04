#include <iostream>
#include <set>
using namespace std;

typedef long long int lli;

const lli N_max = 200000LL;

lli N;
char str[N_max + 5LL];
set<char> _set;
lli fa[N_max + 5], // fa[i] = f(str[0..i])
    fb[N_max + 5]; // fb[i] = f(str[i..N-1])
lli answer;
lli Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--) {
        cin >> N;
        for (int i = 0; i < (int)N; ++i)
            cin >> str[i];
        
        _set.clear();
        for (int i = 0; i < (int)N; ++i) {
            _set.insert(str[i]);
            fa[i] = _set.size();
        }
        _set.clear();
        for (int i = (int)N - 1; i >= 0; --i) {
            _set.insert(str[i]);
            fb[i] = _set.size();
        }

        answer = 0LL;
        for (int i = 0; i + 1 < (int)N; ++i)
            answer = max(answer, fa[i] + fb[i + 1]);
        cout << answer << '\n';
    }
    
    return 0;
}
