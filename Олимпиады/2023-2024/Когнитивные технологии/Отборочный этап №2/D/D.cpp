// author: Danila "akshin_" Aksionov

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

lli a,
    b,
    rad;
double x0,
       best_x,
       best_d1;

void solve();
double ts();
double d(double);
double ts1();
double d1(double);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> rad >> b >> a;

    x0 = ts(); // абсцисса точки касания касательной к озеру из дома Гены.

    best_x = ts1(); // абсцисса лучшей точки.
    best_d1 = d1(best_x);

    cout << fixed << setprecision(20) << best_d1 << '\n';

    return;
}

double ts() {
    double l = 0.0, // левее нужной точки
           r = (double)rad; // правее нужной точки
    // Пусть d(x) = расстояние между точками пересечения прямой и окружности
    // (прямая задаётся точками (x; -sqrt(r^2 - x^2)) и (b; 0); окружность дана),
    // тогда d(l) < d(r).

    for (int _ = 0; _ < 100; ++_) {
        double m1 = (2.0 * l + r) / 3.0,
               m2 = (l + 2.0 * r) / 3.0;
        
        if (d(m1) < d(m2))
            r = m2;
        else
            l = m1;
    }

    return l;
}

// Раньше искал точки пересечения прямой и окружности какой-то хуйнёй (через квадратное уравнение),
// и задача не сдавалась.
// Потом взял алгос с e-maxx'а, и задача решилась мгновенно!
// Ахуеть.
// Как бы алгоритм был правильный изначально, но алгос с e-maxx'а выдавал большую точность, чем моё хуё-маё.
double d(double x) {
    double Ax = x,
           Ay = -sqrt((double)(rad * rad) - x * x),
           Bx = (double)b,
           By = 0.0;
    
    // Старый способ поиска точек пересечения прямой и окружности.
    /* double k = (By - Ay) / (Bx - Ax),
           l = Ay - Ax * (By - Ay) / (Bx - Ax);

    double D = 4.0 * k * k * l * l - 4.0 * (k * k + 1.0) * (l * l - (double)(rad * rad));

    double x1 = (-2.0 * k * l - sqrt(D)) / (2.0 * k + 2),
           x2 = (-2.0 * k * l + sqrt(D)) / (2.0 * k + 2);
    double y1 = -sqrt((double)(rad * rad) - x1 * x1),
           y2 = -sqrt((double)(rad * rad) - x2 * x2); */
    
    // Новый способ поиска точек пересечения прямой и окружности.
    double _A = By - Ay,
           _B = Ax - Bx,
           _C = Bx * Ay - Ax * By;
    
    double x00 = -_A * _C / (_A * _A + _B * _B),
           y00 = -_B * _C / (_A * _A + _B * _B);

    double _d = (double)(rad * rad) - _C * _C / (_A * _A + _B * _B);
    double mult = sqrt(_d / (_A * _A + _B * _B));

    double x1 = x00 + _B * mult,
           x2 = x00 - _B * mult,
           y1 = y00 - _A * mult,
           y2 = y00 + _A * mult;
    
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double ts1() {
    double l = x0,
           r = (double)rad;
    
    for (int _ = 0; _ < 100; ++_) {
        double m1 = (2.0 * l + r) / 3.0,
               m2 = (l + 2.0 * r) / 3.0;
        
        if (d1(m1) < d1(m2))
            r = m2;
        else
            l = m1;
    }

    return l;
}

double d1(double x) {
    double y = sqrt((double)(rad * rad) - x * x);
    double ans = (double)a - y;
    ans += sqrt((x - (double)b) * (x - (double)b) + y * y);
    return ans;
}
