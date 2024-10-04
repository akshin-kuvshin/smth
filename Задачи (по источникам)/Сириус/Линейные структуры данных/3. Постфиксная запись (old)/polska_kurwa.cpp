#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> math_stack;
int result,
    a,
    b;
string S;

int main() {
    getline(cin, S);

    int sz = S.size();
    for (int i = 0; i < sz; ++i) {
        if (S[i] == ' ') continue;

        if ( ('0' <= S[i]) and (S[i] <= '9') )
            math_stack.push(S[i] - '0');
        else {
            b = math_stack.top();
            math_stack.pop();
            a = math_stack.top();
            math_stack.pop();

            if (S[i] == '+')
                math_stack.push(a + b);
            else if (S[i] == '-')
                math_stack.push(a - b);
            else // S[i] == '*'
                math_stack.push(a * b);

        }
    }

    result = math_stack.top();
    cout << result << '\n';
    
    return 0;
}
