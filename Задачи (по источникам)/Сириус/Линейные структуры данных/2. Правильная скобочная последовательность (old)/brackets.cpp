#include <iostream>
#include <string>
#include <stack>
using namespace std;

int sz;
string S;
stack<char> brackets;

int main() {
    cin >> S;

    sz = S.size();
    for (int i = 0; i < sz; ++i) {
        if ((S[i] == '(') or (S[i] == '[') or (S[i] == '{'))
            brackets.push(S[i]);
        else if (S[i] == ')' and brackets.size() and brackets.top() == '(')
            brackets.pop();
        else if (S[i] == ']' and brackets.size() and brackets.top() == '[')
            brackets.pop();
        else if (S[i] == '}' and brackets.size() and brackets.top() == '{')
            brackets.pop();
        else {
            cout << "no\n";
            return 0;
        }
    }

    if (brackets.size())
        cout << "no";
    else
        cout << "yes";
    cout << '\n';

    return 0;
}
