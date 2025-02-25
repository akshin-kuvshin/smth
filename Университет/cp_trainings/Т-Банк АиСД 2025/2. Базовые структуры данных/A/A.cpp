// author: Danila "akshin_" Axyonov

#include <iostream>
#include <stack>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

class min_stack {
private:
    stack<lli> data,
               __min;

public:
    void push(lli val) {
        __min.push(min(val, get_min()));
        data.push(val);
        return;
    }

    void pop() {
        data.pop();
        __min.pop();
        return;
    }

    lli get_min() {
        if (data.empty())
            return INF;
        return __min.top();
    }
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    min_stack s;

    lli q;
    cin >> q;
    while (q--) {
        lli cmd;
        cin >> cmd;
        if (cmd == 1LL) {
            lli val;
            cin >> val;
            s.push(val);
        } else if (cmd == 2LL)
            s.pop();
        else // cmd == 3LL
            cout << s.get_min() << '\n';
    }
    
    return;
}
