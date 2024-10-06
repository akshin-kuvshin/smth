// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e2 + 5LL;

lli Q;
lli N,
    K,
    A[MAX_SIZE];
lli cur,
    answer;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    cur = answer = 0LL;

    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    for (int i = 0; i < (int)N; ++i) {
        if (A[i] >= K)
            cur += A[i];
        else if (A[i] == 0LL and cur) {
            --cur;
            ++answer;
        }
    }
	cout << answer << '\n';
    return;
}
