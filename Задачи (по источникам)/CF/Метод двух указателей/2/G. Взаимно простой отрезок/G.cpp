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

lli gcd_R(lli a, lli b) {
    return ((a && b) ? gcd_R(b, a % b) : (a | b));
}

class gcd_stack {
private:
    stack<lli> A,
               gcd;

public:
    void push(lli elem) {
        A.push(elem);
        if (gcd.empty())
            gcd.push(elem);
        else
            gcd.push(gcd_R(A.top(), gcd.top()));
        return;
    }

    void pop() {
        A.pop();
        gcd.pop();
        return;
    }

    lli top() { return A.top(); }

    lli get_gcd() { return gcd.top(); }

    bool empty() { return A.empty(); }
};

class ds_queue {
private:
    gcd_stack front,
              back;
    
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

    lli get_gcd() {
        if (back.empty())
            return front.get_gcd();
        if (front.empty())
            return back.get_gcd();
        return gcd_R(front.get_gcd(), back.get_gcd());
    }

    bool empty() { return front.empty() and back.empty(); }
};

lli N,
    A[MAX_SIZE];
lli ans = INF;
ds_queue q;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    lli L = 0LL;
    for (lli R = 0LL; R < N; ++R) {
        q.push(A[R]);
        while (!q.empty() and q.get_gcd() == 1LL) {
            ans = min(ans, R - L + 1LL);
            q.pop();
            ++L;
        }
    }
    
    cout << (ans == INF ? -1LL : ans) << '\n';
    return;
}
