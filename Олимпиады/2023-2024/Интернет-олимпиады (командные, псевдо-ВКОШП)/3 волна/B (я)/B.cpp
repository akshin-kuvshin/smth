// author: Danila "akshin_" Axyonov

#include <iostream>
#include <set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          LETTERS = 26LL;

lli N;
char S[MAX_SIZE];
lli cnt[LETTERS + 5LL];
multiset<lli> MS;
lli one,
    two;
bool flag;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i) {
        cin >> S[i];
        ++cnt[S[i] - 'a'];
    }

    for (int i = 0; i < (int)LETTERS; ++i)
        if (cnt[i])
            MS.insert(cnt[i]);

    while ((lli)MS.size() > 1LL) {
        lli _min = *MS.begin(),
            _max = *(--MS.end());
        MS.erase(--MS.end());
        MS.erase(MS.begin());

        if (!flag) // first
            one += _max;
        else // second
            two += _max;
        flag = !flag;

        MS.insert(_min + _max);
    }

    if (one > two)
        cout << "First";
    else
        cout << "Second";
    cout << '\n';

    return;
}
