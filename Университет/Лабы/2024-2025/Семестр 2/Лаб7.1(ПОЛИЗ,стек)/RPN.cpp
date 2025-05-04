#include "RPN.hpp"

#include <iostream>
#include <cstring>
#include "dStack.hpp"
#include "char_ops.hpp"

using namespace std;
using lli = long long int;

double count_RPN(const char* RPN) {
    dStack calc;

    int i = 0;
    while (RPN[i])
    {
        if (RPN[i] == ' ') {
            ++i;
            continue;
        }

        if (is_digit(RPN[i]))
        {
            lli current_number = 0LL;
            while (RPN[i] and is_digit(RPN[i])) {
                current_number = current_number * 10LL + (lli)(RPN[i] - '0');
                ++i;
            }
            calc.push((double)current_number);
        }
        else if (is_operation(RPN[i]))
        {
            if (calc.size < 2) {
                cerr << endl
                     << "(!) Ошибка: недостаточно операндов для выполнения операции." << endl
                     << endl;
                highlight_position_cerr(i);
                cerr << RPN << endl;
                exit(1);
            }

            double d2 = calc.top();
            calc.pop();
            double d1 = calc.top();
            calc.pop();
            if (RPN[i] == '+')
                calc.push(d1 + d2);
            else if (RPN[i] == '-')
                calc.push(d1 - d2);
            else if (RPN[i] == '*')
                calc.push(d1 * d2);
            else // RPN[i] == '/'
                calc.push(d1 / d2);
            
            ++i;
        }
        else
        {
            cerr << endl
                 << "(!) Ошибка: неизвестный символ в ПОЛИЗ-выражении." << endl
                 << endl;
            highlight_position_cerr(i);
            cerr << RPN << endl;
            exit(1);
        }
    }

    if (calc.empty()) { // если стек пуст, при этом мы дошли до сюда (=> не словили ни одной ошибки),
                        // то исходное ПОЛИЗ-выражение (строка RPM) пусто(-а).
        cerr << endl
             << "(!) Ошибка: ПОЛИЗ-выражение пусто." << endl;
        exit(1);
    }
    if (calc.size > 1) {
        cerr << endl
             << "(!) Ошибка: ожидалась операция, ПОЛИЗ-выражение не закончено." << endl
             << endl;
        highlight_position_cerr(i);
        cerr << RPN << endl;
        exit(1);
    }

    return calc.top();
}

void highlight_position_cerr(int pos) {
    for (int i = 0; i < pos; ++i)
        cerr << ' ';
    cerr << '|' << endl;
    for (int i = 0; i < pos; ++i)
        cerr << ' ';
    cerr << 'V' << endl;
    return;
}
