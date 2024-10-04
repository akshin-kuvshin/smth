#include <iostream>
#include <stack>
using namespace std;

const int N_max = 2e3;

int N,
    A[N_max + 5],
    ind = 0; // индекс вагона на первом пути, стоящего ближе всего к тупику
stack<int> twopac;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int counter = 1; counter <= N; ++counter) { // какой вагон мы сейчас стремимся вывести на второй путь
        if (twopac.size()) if (twopac.top() == counter) {
            twopac.pop();
            continue;
        }
        
        if (ind == N) {
            cout << "NO\n";
            return 0;
        }

        do {
            twopac.push(A[ind++]);
        } while ( (twopac.top() != counter) and (ind < N) );
        
        if (twopac.top() == counter)
            twopac.pop();
        else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
