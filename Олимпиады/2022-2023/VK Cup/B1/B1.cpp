#include <iostream>
#include <set>
using namespace std;

const int N_max = 1e2;

int N,
    A[N_max + 5],
    full_sum, // общий размер всех файлов
    copied_sum; // размер скопированной части
set<int> coincidences;

void input();
void solution();
void output();

int main() {
    input();
    solution();
    output();

    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        full_sum += A[i];
    }
    return;
}

void solution() {
    for (int i = 0; i < N; ++i) {
        int full_current = A[i];
        
        for (int bytes = 0; bytes <= full_current; ++bytes) {
            copied_sum += (bytes ? 1 : 0);

            int full_progress_bar = 100 * copied_sum / full_sum,
                current_progress_bar = 100 * bytes / full_current;
            
            if (current_progress_bar == full_progress_bar)
                coincidences.insert(current_progress_bar);
        }
    }
    return;
}

void output() {
    for (set<int>::iterator it = coincidences.begin(); it != coincidences.end(); ++it)
        cout << *it << '\n';
    return;
}
