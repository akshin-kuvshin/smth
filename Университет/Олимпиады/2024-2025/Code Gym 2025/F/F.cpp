// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = 100LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli Q;
    cin >> Q;
    while (Q--)
        solve();
    
    return 0;
}

void solve() {
    lli x;
    cin >> x;

    lli x_copy = x;
    vector<lli> bx(MAX_SIZE);
    {
        int i = 0;
        while (x_copy) {
            bx[i++] = x_copy % 2LL;
            x_copy /= 2LL;
        }
    }

    vector<lli> ans;
    {
        int i = 0;
        lli pushed = 0LL;
        while (pushed < x) {
            bx[i + 1] += bx[i] / 2LL;
            bx[i] %= 2LL;
            bx[i + 2] += bx[i + 1] / 2LL;
            bx[i + 1] %= 2LL;

            if (not bx[i])
                ans.pb(0LL);
            else { // bx[i]
                if (bx[i + 1] == 0LL) {
                    ans.pb(1LL);
                    pushed += (1LL << i);
                } else { // bx[i + 1] == 1LL
                    ans.pb(-1LL);
                    ++bx[i + 1];
                }
            }

            ++i;
        }
    }

    cout << ans.size() << '\n';
    for (lli _move : ans)
        cout << _move << ' ';
    cout << '\n';    
    return;
}
