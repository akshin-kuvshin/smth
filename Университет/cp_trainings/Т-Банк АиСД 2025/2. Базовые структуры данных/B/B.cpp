// author: Danila "akshin_" Axyonov

#include <iostream>
#include <stack>
#include <vector>
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

    lli top() {
        return data.top();
    }

    lli get_min() {
        if (empty())
            return INF;
        return __min.top();
    }

    bool empty() {
        return data.empty();
    }
};

class min_queue {
private:
    min_stack b,
              e;
    
    void transite() {
        while (not e.empty()) {
            b.push(e.top());
            e.pop();
        }
        return;
    }

public:
    void push(lli val) {
        e.push(val);
        return;
    }

    void pop() {
        if (b.empty())
            transite();
        b.pop();
        return;
    }

    lli get_min() {
        return min(b.get_min(), e.get_min());
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
    lli n,
        k;
    cin >> n >> k;
    vector<lli> a(n);
    for (auto& elem : a)
        cin >> elem;
    
    min_queue q;
    lli i = 0LL;
    while (i < k)
        q.push(a[i++]);
    cout << q.get_min() << ' ';
    
    while (i < n) {
        q.pop();
        q.push(a[i++]);
        cout << q.get_min() << ' ';
    }
    cout << '\n';
    
    return;
}
