#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define health first
#define power second
#define ERROR -1
using namespace std;

typedef long long int lli;

// Constants
const lli T_max = 1e2,
          N_max = 1e5;
const string results[] = {"NO\n", "YES\n"};

// Variables
lli tests_number;
bool answers[T_max + 5];

lli N,
    genos_power;
pair<lli, lli> monsters[N_max + 5];

// Functions
void input();
void solution(lli);
bool comp(const pair<lli, lli>&, const pair<lli, lli>&);
lli get_punches_number(lli, lli, lli);

int main() {
    cin >> tests_number;

    for (lli t = 0; t < tests_number; ++t) {
        input();
        solution(t);
    }

    for (lli t = 0; t < tests_number; ++t)
        cout << results[answers[t]];
    
    return 0;
}

void input() {
    cin >> N >> genos_power;
    for (lli i = 0; i < N; ++i)
        cin >> monsters[i].health;
    for (lli i = 0; i < N; ++i)
        cin >> monsters[i].power;    
    return;
}

void solution(lli test_index) {
    // Сортируем по возрастанию силы (в случае равенства - по убыванию здоровья)
    sort(monsters, monsters + N, comp);

    /* cout << '\n';
    for (lli i = 0; i < N; ++i)
        cout << monsters[i].health << ' ' << monsters[i].power << '\n';
    cout << '\n'; */

    lli total_damage = 0,
        punches_number;

    total_damage += genos_power;
    for (lli i = 0; i < N; ++i) {
        if (genos_power <= 0)
            return;

        monsters[i].health -= total_damage;
        if (monsters[i].health <= 0)
            continue;
        
        punches_number = get_punches_number(genos_power, monsters[i].health, monsters[i].power);
        // cout << genos_power << ' ' << monsters[i].health << ' ' << monsters[i].power << ' ' << punches_number << '\n';

        if (punches_number == ERROR)
            return;

        total_damage += (2 * genos_power - (punches_number + 1) * monsters[i].power) * punches_number / 2;
        genos_power -= monsters[i].power * punches_number;
    }
    
    answers[test_index] = true;
    return;
}


bool comp(const pair<lli, lli> &m1, const pair<lli, lli> &m2) {
    if (m1.power == m2.power)
        return m1.health > m2.health;
    return m1.power < m2.power;
}

lli get_punches_number(lli a0, lli h, lli p) {
    // Просто решаем квадратное уравнение.
    /* Выводится через то, что сумма ударов должна быть больше или равна здоровью монстра, но при этом минимальной.
    Sn >= h, Sn - minimal possible

    a0 = genos_power
    d = -monsters[i].power
    n = punches_number

    Задача: найти минимально возможное целое n */

    lli d = (p - 2 * a0) * (p - 2 * a0) - 8 * p * h;
    if (d < 0)
        return ERROR;

    double punches_number = (-p + 2.0 * a0 - sqrt(d)) / (2.0 * p);

    if (punches_number <= 0)
        punches_number = (-p + 2.0 * a0 + sqrt(d)) / (2.0 * p);
    if (punches_number <= 0)
        return ERROR;
    
    lli n1 = (lli)punches_number,
        n2 = (lli)punches_number + 1;
    
    if ((2 * a0 - (n1 + 1) * p) * n1 / 2 >= h)
        return n1;
    return n2;
}
