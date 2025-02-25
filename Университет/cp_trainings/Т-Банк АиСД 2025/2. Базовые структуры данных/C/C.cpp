// author: Danila "akshin_" Axyonov

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    string s;
    getline(cin, s);
    stringstream input;
    input << s;

    stack<lli> st;
    while (not input.eof()) {
        string x;
        input >> x;
        if (x.empty())
            break;
        else if (x == "+") {
            lli x2 = st.top();
            st.pop();
            lli x1 = st.top();
            st.pop();
            st.push(x1 + x2);
        } else if (x == "-") {
            lli x2 = st.top();
            st.pop();
            lli x1 = st.top();
            st.pop();
            st.push(x1 - x2);
        } else if (x == "*") {
            lli x2 = st.top();
            st.pop();
            lli x1 = st.top();
            st.pop();
            st.push(x1 * x2);
        } else // x is a number
            st.push(stoll(x));
    }
    
    cout << st.top() << '\n';
    return;
}
