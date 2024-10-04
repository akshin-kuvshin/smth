#include <iostream>
#include <queue>
using namespace std;

const int N = 5;

queue<int> first,
           second;
int steps_number,
    tmp,
    F, // карточки, выставляемые первым и вторым игроками соответственно
    S;

int main() {
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        first.push(tmp);
    }
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        second.push(tmp);
    }
    
    while (steps_number < 1000000) {
        if (!first.size()) {
            cout << "second " << steps_number << '\n';
            return 0;
        } else if (!second.size()) {
            cout << "first " << steps_number << '\n';
            return 0;
        }

        F = first.front();
        first.pop();
        S = second.front();
        second.pop();

        // P.S.: случай равенства не рассматривается, т.к. это оговорено в условии
        if (!F and (S == 9)) {
            first.push(F);
            first.push(S);
        } else if (!S and (F == 9)) {
            second.push(F);
            second.push(S);
        } else if (F > S) {
            first.push(F);
            first.push(S);
        } else { // F < S
            second.push(F);
            second.push(S);
        }
        
        ++steps_number;
    }

    cout << "botva\n";
    return 0;
}
