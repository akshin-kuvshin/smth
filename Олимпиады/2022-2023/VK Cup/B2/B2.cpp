#include <iostream>
#include <cmath>
#define lli long long int
#define Segment pair<long long int, long long int>
#define begin first
#define end second
using namespace std;

const int MAX_SIZE = 1e2;
const double eps = 1e-6;

int N;
lli A[MAX_SIZE + 5];
lli copied, // объём переданной части
    full; // ПОЛНЫЙ объём передаваемых данных

// Разбиение числа A[i] на 101 отрезок,
// на каждом из которых current_progress_bar будет показывать уникальное значение.
Segment segments[MAX_SIZE + 5];
int top;

// Совпадения
bool coincidences[MAX_SIZE + 5];

void input();
void solution();
void output();
void divide_into_segments(lli);

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
        full += A[i];
    }
    return;
}

void solution() {
    for (int i = 0; i < N; ++i) {
        lli current = A[i];
        divide_into_segments(current);
        
        // Debug
        /* cout << current << '\n';
        for (int k = 0; k < top; ++k)
            cout << segments[k].begin << '\t' << segments[k].end << '\n';
        cout << '\n'; */

        // TODO!!!!!!!!!!
        // Сделать проверку по всем segments[i].begin и segments[i].end
        int current_progress_bar,
            full_progress_bar;
        for (int k = 0; k < top; ++k) {
            current_progress_bar = (int)(100LL * segments[k].begin / current);
            full_progress_bar = (int)(100LL * (copied + segments[k].begin) / full);
            if (current_progress_bar == full_progress_bar)
                coincidences[current_progress_bar] = true;
            
            current_progress_bar = (int)(100LL * segments[k].end / current);
            full_progress_bar = (int)(100LL * (copied + segments[k].end) / full);
            if (current_progress_bar == full_progress_bar)
                coincidences[current_progress_bar] = true;
        }

        copied += current;
    }
    return;
}

void output() {
    for (int i = 0; i <= MAX_SIZE; ++i)
        if (coincidences[i])
            cout << i << '\n';
    return;
}

void divide_into_segments(lli current) {
    // Удаляем предыдущее разбиение
    top = 0;

    // Частный случай, когда не получается разбить на 101 отрезок
    // (число 100 взял по приколу - это не ломает логики).
    if (current <= 100LL) {
        for (lli start = 0LL; start <= current; ++start)
            segments[top++] = make_pair(start, start);
        return;
    }

    // Общий случай разбиения.
    lli start = 0LL;
    lli finish;
    for (int cpb = 1; cpb <= 100; ++cpb) { // cpb <=> current_progress_bar
        finish = (lli)cpb * current / 100LL;
        if (100.0 * finish / current < (double)cpb) // возможен НЕДОбор (но невозможен ПЕРЕбор)
            ++finish;
        
        segments[top++] = make_pair(start, finish - 1);
        start = finish;
    }

    // cpb == 100 (в цикл не входит + границы постоянные => добавляем отдельно)
    segments[top++] = make_pair(current, current);

    return;
}
