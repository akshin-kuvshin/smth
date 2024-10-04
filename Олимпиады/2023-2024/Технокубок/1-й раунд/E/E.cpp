// author: Danila "akshin_" Aksionov
// Решение на 55 баллов
// В решении нет обработки того, что запрос может быть немного изменённым именем ученика, поэтому он проходит не все тесты.
// Написано ужасно коряво, но прошу меня понять, ведь было крайне мало времени.

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N_max = (lli)1e2 + 5LL,
          G_max = 9LL + 5LL,
          D_max = 8LL + 5LL;

lli N,
    G,
    D;

class Group {
public:
    lli on_three[D_max],
        on_four[D_max],
        on_five[D_max];
    bool tasks[D_max][40][N_max]; // tasks[номер_дня][номер_задачи][номер_ученика]
    vector<plli> parsed_tasks_names; // пара: номер_задачи - номер_дня

    void input() {
        for (int i = 1; i <= (int)D; ++i)
            cin >> on_three[i] >> on_four[i] >> on_five[i];

        string S;
        cin >> S;
        while ('A' <= S[0] and S[0] <= 'Z') {
            lli letter = S[0] - 'A';
            lli day = S[1] - '0';
            parsed_tasks_names.pb(mp(letter, day));
            cin >> S;
        }

        lli student_id = 0LL;
        for (char c : S)
            student_id = student_id * 10LL + c - '0';
        for (plli task : parsed_tasks_names) {
            char tmp;
            cin >> tmp;
            bool is_solved = ((tmp == '+') ? true : false);
            tasks[task.second][task.first][student_id] = is_solved;
        }
        for (int _ = 1; _ < (int)N; ++_) {
            cin >> student_id;

            for (plli task : parsed_tasks_names) {
                char tmp;
                cin >> tmp;
                bool is_solved = ((tmp == '+') ? true : false);
                tasks[task.second][task.first][student_id] = is_solved;
            }
        }

        return;
    }
};
Group groups[G_max];

class Student {
public:
    lli id;
    string name;
    lli gs[D_max];
    lli mark;

    void input() {
        cin >> id >> name;
        for (int i = 1; i <= (int)D; ++i)
            cin >> gs[i];
        return;
    }

    void count_mark() {
        lli lim3 = 0LL,
            lim4 = 0LL,
            lim5 = 0LL;
        for (int i = 1; i <= (int)D; ++i) {
            lim3 += groups[gs[i]].on_three[i];
            lim4 += groups[gs[i]].on_four[i];
            lim5 += groups[gs[i]].on_five[i];
        }

        lli solved = 0LL;
        for (int i = 1; i <= (int)D; ++i) {
            Group curg = groups[gs[i]];

            for (plli task : curg.parsed_tasks_names) {
                if (task.second != (lli)i)
                    continue;
                solved += (lli)curg.tasks[i][task.first][id];
            }
        }

        if (solved >= lim5)
            mark = 5LL;
        else if (solved >= lim4)
            mark = 4LL;
        else if (solved >= lim3)
            mark = 3LL;
        else
            mark = 2LL;
        return;
    }
};
Student students[N_max];

void solve();
lli find_student(string);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> N >> G >> D;
    for (int i = 1; i <= (int)N; ++i)
        students[i].input();
    for (int i = 1; i <= (int)G; ++i)
        groups[i].input();
    
    for (int i = 1; i <= (int)N; ++i)
        students[i].count_mark();
    
    lli Q;
    cin >> Q;
    while (Q--) {
        string query;
        cin >> query;

        if ('0' <= query[0] and query[0] <= '9') {
            lli student_id = 0LL;
            for (char c : query)
                student_id = student_id * 10LL + c - '0';
            cout << students[student_id].mark << '\n';
        } else {
            lli student_id = find_student(query);
            if (student_id != -1LL)
                cout << students[student_id].mark << '\n';
            else
                cout << "Not Found\n";
        }
    }
    
    return;
}

lli find_student(string q) {
    for (int i = 1; i <= (int)N; ++i)
        if (students[i].name == q)
            return (lli)i;
    return -1LL;
}
