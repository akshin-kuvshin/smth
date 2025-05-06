// author: Danila "akshin_" Axyonov

#include "RPN.hpp"

#include <iostream>
#include <cstring>
#include "Stack.hpp"
#include "char_ops.hpp"

using namespace std;
using lli = long long int;
using ulli = unsigned long long int;



int priority(char operation) {
    switch (operation) {
    case '(':
        return 0;
    // case ')':        // закомментировано, т.к. закрывающая скобка никогда не попадает в стек операций.
    //     return 1;
    case '+': case '-':
        return 2;
    case '*': case '/':
        return 3;
    }

    cerr << endl
         << "(!) Ошибка: функция priority() была вызвана для нерассматриваемой операции '" << operation << "'." << endl;
    exit(1);
}



void convert_to_RPN
(const char* traditional,
 char* RPN)
{
    int top = 0; // RPN_top
    Stack<char> signs;
    Stack<int> indexes; // - понадобится нам в одном-единственном месте (см. "!!!").

    for (int i = 0; traditional[i];)
    {
        if (traditional[i] == ' ') {
            ++i;
            continue;
        }

        if (is_digit(traditional[i]))
        {
            if (traditional[i] == '0' and traditional[i + 1] and is_digit(traditional[i + 1])) {
                cerr << endl
                     << "(!) Ошибка: обнаружен незначащий нуль в числе." << endl
                     << endl;
                highlight_position_cerr(i);
                cerr << traditional << endl;
                exit(1);
            }
            while (traditional[i] and is_digit(traditional[i]))
                RPN[top++] = traditional[i++];
            RPN[top++] = ' ';
        }
        else if (is_letter(traditional[i]))
        {
            // Допустим поддержку не только одиночных букв, но и целых слов,
            // которые, по сути, наравне с одиночными буквами, будут являться переменными.
            while (traditional[i] and is_letter(traditional[i]))
                RPN[top++] = traditional[i++];
            RPN[top++] = ' ';
        }
        else if (is_operation(traditional[i]) or is_parenthesis(traditional[i]))
        {
            if (traditional[i] == '(') {
                signs.push(traditional[i]);
                indexes.push(i);
            } else if (traditional[i] == ')') {
                while (not signs.empty() and signs.top() != '(') {
                    char sign = signs.top();
                    signs.pop();
                    indexes.pop();

                    RPN[top++] = sign;
                    RPN[top++] = ' ';
                }
                if (signs.empty()) {
                    cerr << endl
                         << "(!) Ошибка: обнаружена закрывающая скобка, которой не соответствует никакая открывающая." << endl
                         << endl;
                    highlight_position_cerr(i);
                    cerr << traditional << endl;
                    exit(1);
                }
                signs.pop();
                indexes.pop();
            } else {
                while (not signs.empty() and priority(signs.top()) >= priority(traditional[i])) {
                    char sign = signs.top();
                    signs.pop();
                    indexes.pop();

                    RPN[top++] = sign;
                    RPN[top++] = ' ';
                }
                signs.push(traditional[i]);
                indexes.push(i);
            }

            ++i;
        }
        else
        {
            cerr << endl
                 << "(!) Ошибка: обнаружен неизвестный символ в исходном выражении." << endl
                 << endl;
            highlight_position_cerr(i);
            cerr << RPN << endl;
            exit(1);
        }
    }

    while (not signs.empty()) {
        char sign = signs.top();
        int ind = indexes.top();
        signs.pop();
        indexes.pop();

        if (sign == '(') {
            cerr << endl
                 << "(!) Ошибка: обнаружена открывающая скобка, которой не соответствует никакая закрывающая." << endl
                 << endl;
            highlight_position_cerr(ind); // !!!
            cerr << traditional << endl;
            exit(1);
        }

        RPN[top++] = sign;
        RPN[top++] = ' ';
    }

    if (top == 0) {
        cerr << endl
             << "(!) Ошибка: исходное выражение пусто." << endl;
        exit(1);
    }
    RPN[top - 1] = '\0';    // (top - 1), потому что в конце всегда ставим пробел =>
                            // => под индексом (top - 1) находится "висячий" пробел =>
                            // => запишем нуль-терминатор туда.

    return;
}



int find_var
(const char v[MAX_VAR_NAME_LEN],
 const char vars[MAX_VARS_NUMBER][MAX_VAR_NAME_LEN],
 int vars_top)
{
    for (int i = 0; i < vars_top; ++i)
        if (strcmp(v, vars[i]) == 0)
            return i;
    return NOT_FOUND;
}



double count_RPN
(const char* RPN)
{
    Stack<double> calc;
    char vars[MAX_VARS_NUMBER][MAX_VAR_NAME_LEN]; // реализуемо с помощью списка.
    int vars_vals[MAX_VARS_NUMBER]; // варс_валс)
    int vars_top = 0; // vars_top
    bool was_var_requested = false;

    int i = 0;
    while (RPN[i])
    {
        if (RPN[i] == ' ') {
            ++i;
            continue;
        }

        if (is_digit(RPN[i]))
        {
            if (RPN[i] == '0' and RPN[i + 1] and is_digit(RPN[i + 1])) {
                cerr << endl
                     << "(!) Ошибка: обнаружен незначащий нуль в числе." << endl
                     << endl;
                highlight_position_cerr(i);
                cerr << RPN << endl;
                exit(1);
            }
            ulli current_number = 0ULL;
            while (RPN[i] and is_digit(RPN[i]))
                current_number = current_number * 10ULL + (ulli)(RPN[i++] - '0');
            calc.push((double)current_number);
        }
        else if (is_letter(RPN[i]))
        {
            char v[MAX_VAR_NAME_LEN];
            int v_top = 0;
            while (RPN[i] and is_letter(RPN[i]))
                v[v_top++] = RPN[i++];
            v[v_top] = '\0';

            int ind = find_var(v, vars, vars_top);
            if (ind == NOT_FOUND) {
                lli v_val;
                if (not was_var_requested) {
                    cout << endl;
                    was_var_requested = true;
                }
                cout << "Введите значение переменной " << v << ':' << endl
                     << "> ";
                cin >> v_val;

                strcpy(vars[vars_top], v);
                vars_vals[vars_top] = v_val;
                ind = vars_top;
                ++vars_top;
            }
            calc.push((double)vars_vals[ind]);
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
            switch (RPN[i]) {
            case '+':
                calc.push(d1 + d2);
                break;
            case '-':
                calc.push(d1 - d2);
                break;
            case '*':
                calc.push(d1 * d2);
                break;
            case '/':
                calc.push(d1 / d2);
                break;
            default:
                cerr << endl
                     << "(!) Ошибка: достигнута недостижимая точка программы." << endl
                     << endl;
                highlight_position_cerr(i);
                cerr << RPN << endl;
                exit(1);
            }
            
            ++i;
        }
        else
        {
            cerr << endl
                 << "(!) Ошибка: обнаружен неизвестный символ в ПОЛИЗ-выражении." << endl
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
