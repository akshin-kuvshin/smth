// author: Danila "akshin_" Axyonov

// Задание 6 (двусвязный список с фиктивными головой и хвостом):
//      Добавьте в список заданный элемент после первого такого же элемента.
//      В случае, если элемент в списке не присутствует, добавьте его в хвост.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DoubleLinkedList.hpp"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

const int N_MAX = 27;
const int _RAND_MIN = -N_MAX,
          _RAND_MAX = N_MAX;

int randint(int _min, int _max);

int main() {
    srand(time(nullptr));

    int n;
    cout << "Введите количество элементов в списке (но не больше, чем " << N_MAX << "):" << endl
         << "> ";
    cin >> n;
    if (n < 0) {
        cerr << endl
             << "(!) Ошибка: длина списка не может быть отрицательным числом." << endl;
        exit(1);
    }
    if (n > N_MAX) {
        cerr << endl
             << "(!) Ошибка: длина списка не может быть больше, чем " << N_MAX << '.' << endl;
        exit(1);
    }

    DoubleLinkedList<int> l;
    for (int _ = 0; _ < n; ++_)
        l.push_back(randint(_RAND_MIN, _RAND_MAX));
    cout << endl
         << "Сгенерированный список:" << endl;
    l.print();

    int x;
    cout << endl
         << "Введите число, которое Вы хотите добавить в список после первого его" << endl
         << "в этот список вхождения (в случае, если введённое Вами число в списке" << endl
         << "отсутствует, оно будет добавлено в конец (хвост) списка):" << endl
         << "> ";
    cin >> x;

    Node<int>* p = l.find_val(x);
    if (p)  l.push_after(p, x);
    else    l.push_back(x);

    cout << endl
         << "Изменённый список:" << endl;
    l.print();

    cout << endl;
    return 0;
}

int randint(int _min, int _max) {
    return rand() % (_max - _min + 1) + _min;
}
