// author: Danila "akshin_" Axyonov

#include <iostream>
#include <stack>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1e5 + 5LL,
          INF = (lli)1e18 + 1LL;

class minmax_stack {
private:
    stack<lli> A,
               _min,
               _max;

public:
    minmax_stack() {
        _min.push(INF);
        _max.push(-INF);
        return;
    }

    void push(lli elem) {
        A.push(elem);
        _min.push(min(A.top(), _min.top()));
        _max.push(max(A.top(), _max.top()));
        return;
    }

    void pop() {
        A.pop();
        _min.pop();
        _max.pop();
        return;
    }

    lli top() { return A.top(); }

    lli get_min() { return _min.top(); }

    lli get_max() { return _max.top(); }

    bool empty() { return A.empty(); }
};

class ds_queue {
private:
    minmax_stack front,
                 back;
    
    void transfer() {
        while (!back.empty()) {
            front.push(back.top());
            back.pop();
        }
        return;
    }

    lli get_min() { return min(front.get_min(), back.get_min()); }

    lli get_max() { return max(front.get_max(), back.get_max()); }

public:
    void push(lli elem) {
        back.push(elem);
        return;
    }

    void pop() {
        if (front.empty())
            transfer();
        front.pop();
        return;
    }

    lli d() { return get_max() - get_min(); }
};

lli N,
    A[MAX_SIZE];
lli k;
lli ans;
ds_queue q;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> k;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    lli L = 0LL;
    for (lli R = 0LL; R < N; ++R) {
        q.push(A[R]);
        while (q.d() > k) {
            q.pop();
            ++L;
        }
        ans += R - L + 1LL;
    }
    
    cout << ans << '\n';
    return;
}
