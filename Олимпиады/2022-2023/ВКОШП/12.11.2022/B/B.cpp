#include <iostream>
#include <cmath>
#define x first
#define y second
using namespace std;

pair<int, int> in, // Внутри круга
               out; // Снаружи круга
// Постоянная прямая (недвижимая)
int a,
    b,
    c;
pair<int, int> O; // Центр окружности
double old_r,
       r; // Радиус новой (изменённой окружности)

bool one_dot();
double cr_pr(pair<double, double>, pair<double, double>);

int main() {
    cin >> O.x >> O.y >> old_r;
    cin >> a >> b >> c;
    cin >> in.x >> in.y >> out.x >> out.y;

    if ((in.x - O.x) * (in.x - O.x) + (in.y - O.y) * (in.y - O.y) <= old_r * old_r and
        (out.x - O.x) * (out.x - O.x) + (out.y - O.y) * (out.y - O.y) <= old_r * old_r) {
        cout << "YES\n";
    } else if ((in.x - O.x) * (in.x - O.x) + (in.y - O.y) * (in.y - O.y) <= old_r * old_r and
               (out.x - O.x) * (out.x - O.x) + (out.y - O.y) * (out.y - O.y) > old_r * old_r) {
        if (one_dot())
            cout << "YES\n";
        else
            cout << "NO\n";
    } else if ((in.x - O.x) * (in.x - O.x) + (in.y - O.y) * (in.y - O.y) <= old_r * old_r and
               (out.x - O.x) * (out.x - O.x) + (out.y - O.y) * (out.y - O.y) > old_r * old_r) {
        swap(in, out);
        if (one_dot())
            cout << "YES\n";
        else
            cout << "NO\n";
    } else {
        if (((out.y - in.y == a) or (in.y - out.y == a)) and ((out.x - in.x == b) or (in.x - out.x == b)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

bool one_dot() {
    r = sqrt((O.x - in.x) * (O.x - in.x) + (O.y - in.y) * (O.y - in.y));

    // С Хабра (длина перпендикуляра)
    double h = (a * O.x + b * O.y + c) / sqrt(a * a + b * b);

    double cross_product = cr_pr(make_pair(1, - a / (double)b - c / (double)b), make_pair(O.x, O.y));

    int sign;
    if (cross_product >= 0) // прямая под центром
        sign = 1;
    else // прямая над центром
        sign = -1;

    int a1 = a, b1 = b; double c1; // первая касательная
    int a2 = a, b2 = b; double c2; // вторая касательная
    
    // Косинус через тангенс
    double _cos = sqrt(1. / (((double)a * a / b / b) + 1));

    // Считаем смещение вдоль прямой Оу с учётом знака (знак зависит от положения прямой и центра окружости)
    if (h < r) {
        c1 = c + (-sign * (r - h) / _cos);
        c2 = c + (sign * (r + h) / _cos);
    } else if (h == r) {
        c1 = c;
        c2 = c + sign * (h + r) / _cos;
    } else { // h > r
        c1 = c + (sign * (h - r) / _cos);
        c2 = c + (sign * (h + r) / _cos);
    }

    double cr_pr_with_O,
           cr_pr_with_out;
    
    // Проверяем точку вне круга относительно первой касательной (случай, когда она на ней - хороший)
    cr_pr_with_O = cr_pr(make_pair(1, - a / (double)b - c1 / (double)b), make_pair(O.x, O.y));
    cr_pr_with_out = cr_pr(make_pair(1, - a / (double)b - c1 / (double)b), make_pair(out.x, out.y));
    if (cr_pr_with_O > 0) {
        if (cr_pr_with_out < 0)
            return false;
    } else { // cr_pr_with_O < 0
        if (cr_pr_with_out > 0)
            return false;
    }
    
    // Проверяем относительно второй касательной
    cr_pr_with_O = cr_pr(make_pair(1, - a / (double)b - c2 / (double)b), make_pair(O.x, O.y));
    cr_pr_with_out = cr_pr(make_pair(1, - a / (double)b - c2 / (double)b), make_pair(out.x, out.y));
    if (cr_pr_with_O > 0) {
        if (cr_pr_with_out < 0)
            return false;
    } else { // cr_pr_with_O < 0
        if (cr_pr_with_out > 0)
            return false;
    }

    return true;
}

double cr_pr(pair<double, double> vect1, pair<double, double> vect2) {
    return vect1.x * vect2.y - vect1.y * vect2.x;
}
