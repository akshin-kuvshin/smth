// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli MAX_SIZE = (lli)1.5e5 + 5LL,
          INF = (lli)1e18 + 1LL;



class stack_with_min {
private:
    vector<lli> data;
    vector<lli> _min;

public:
    void push(lli elem) {
        data.pb(elem);
        if (_min.empty())
            _min.pb(elem);
        else
            _min.pb(min(_min.back(), elem));
        return;
    }

    void pop() {
        data.pop_back();
        _min.pop_back();
        return;
    }

    lli top() { return data.back(); }

    lli get_min() {
        if (_min.empty())
            return INF;
        return _min.back();
    }

    bool empty() { return data.empty(); }
};



class ds_queue {
private:
    stack_with_min front;
    stack_with_min back;

    void transfer() {
        while (!back.empty()) {
            front.push(back.top());
            back.pop();
        }
        return;
    }

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

    lli get_min() { return min(front.get_min(), back.get_min()); }
};



lli N,
    A[MAX_SIZE],
    K;
ds_queue q;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    for (int i = 0; i < (int)K; ++i)
        q.push(A[i]);
    cout << q.get_min() << ' ';
    for (int i = (int)K; i < (int)N; ++i) {
        q.push(A[i]);
        q.pop();
        cout << q.get_min() << ' ';
    }
    cout << '\n';
    
    return;
}
