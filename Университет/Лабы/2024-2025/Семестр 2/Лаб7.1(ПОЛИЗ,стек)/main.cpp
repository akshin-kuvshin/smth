// author: Danila "akshin_" Axyonov

/*
Задание:
    Написать программу формирования и вычисления ПОЛИЗ-выражения,
    содержащего буквы и многозначные числа.
    При работе со стеком предусмотреть проверку
    на ошибки ввода формулы (потеряна открывающая или
    закрывающая скобка, потеряна операция, потерян операнд).
*/

#include <iostream>
// #include <cstdio>
#include "RPN.hpp"
#include "char_ops.hpp"

using namespace std;

const int MAX_LEN = 1'000;

int main() {
    system("clear");

    int cmd;
    cout << "\tВыберите опцию:" << endl
         << "1) Сформировать ПОЛИЗ-выражение на основе традиционной (инфиксной) его записи;" << endl
         << "2) Вычислить результат уже готового численного (не содержащего букв) ПОЛИЗ-выражения." << endl
         << "> " << flush;
    cin >> cmd;

    if (cmd != 1 and cmd != 2) {
        cerr << endl
             << "(!) Ошибка: введена несуществующая опция." << endl;
        exit(1);
    }



    if (cmd == 1)
    {
        char traditional[MAX_LEN];
        cout << endl
             << "Введите выражение в его традиционной (инфиксной) форме записи:" << endl
             << "> " << flush;
        getchar();
        gets(traditional);

        char RPN[MAX_LEN];
        convert_to_RPN(traditional, RPN);
        cout << endl
             << "Выражение в форме ПОЛИЗ: " << RPN << endl;
        
        bool is_numeric_RPN = true;
        for (int i = 0; RPN[i]; ++i)
            if (not (RPN[i] == ' ' or is_digit(RPN[i]) or is_operation(RPN[i]))) {
                is_numeric_RPN = false;
                break;
            }
        if (is_numeric_RPN) {
            double res = count_RPN(RPN);
            cout << endl
                 << "Введённое Вами выражение, наряду с его записью в ПОЛИЗ, не содержит букв/слов, поэтому его результат может быть однозначно посчитан." << endl
                 << "Результат: " << res << '.' << endl;
        }
    }
    else // cmd == 2
    {
        char RPN[MAX_LEN];
        cout << endl
             << "Введите численное ПОЛИЗ-выражение для вычисления его результата:" << endl
             << "> " << flush;
        getchar();
        gets(RPN);
        
        double res = count_RPN(RPN);
        cout << endl
             << "Результат: " << res << endl;
    }



    return 0;
}
