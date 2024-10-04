#include <iostream>
#include <deque>
using namespace std;

int N,
    tmp;
deque<int> first_half,
           second_half;
char _switch;

void update();

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> _switch;

        if (_switch == '+') {
            cin >> tmp;
            second_half.push_back(tmp);
            update();
        } else if (_switch == '*') {
            cin >> tmp;
            second_half.push_front(tmp);
            update();
        } else { // _switch == '-'
            cout << first_half.front() << '\n';
            first_half.pop_front();
            update();
        }
    }

    return 0;
}

void update() {
    if (first_half.size() == second_half.size())
        return;
    
    int X3 = second_half.front();
    second_half.pop_front();
    first_half.push_back(X3);
    return;
}
