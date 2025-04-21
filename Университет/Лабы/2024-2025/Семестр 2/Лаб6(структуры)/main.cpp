// author: Danila "akshin_" Axyonov

/*
ЗАДАНИЕ:
1) Определите структуру Stud, содержащую информацию о студенте: 
    фамилию,
    имя,
    отчество,
    номер группы,
    оценки за три экзaменa.
2) Создайте динамический массив course[N] (N - число студентов, вводится с клавиатуры),
   заполните его данными из файла data.txt. Если N задано больше, чем записей в файле,
   то вывести соответствующее сообщение, например, "Файл прочитан до конца, количество
   записей = <-число->".
3) <-ВАРИАНТ 11->
   Вывести результаты аттестации k-ой группы (k вводится с клавиатуры) по убыванию суммы
   баллов (в виде: фамилия - имя - сумма баллов). Или вывести сообщение "Группы с номером
   <-номер группы-> нет".
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include "Stud.hpp"

using namespace std;

const char* data_filename = "data.txt";

bool marks_sum_desc_cmp(Stud s1, Stud s2);

int main() {
    system("clear");





    int n;
    cout << "Введите число студентов, с которыми будете работать:" << endl
         << "> ";
    cin >> n;
    cout << endl;
    assert(n > 0 and "Ошибка: число студентов должно быть натуральным числом.");

    Stud* course = new Stud[n];
    assert(course and "Ошибка: не удалось выделить память под указанное число студентов.");

    ifstream fin;
    fin.open(data_filename);
    if (not fin.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << data_filename << ", содержащий информацию о студентах." << endl;
        return 1;
    }

    int top = 0;
    for (; not fin.eof() and top < n; ++top) {
        fin >> course[top].last_name
            >> course[top].first_name
            >> course[top].patronymic
            >> course[top].group;
        course[top].marks_sum = 0;
        for (int i = 0; i < __SUBJECTS_AMOUNT; ++i) {
            fin >> course[top].marks[i];
            course[top].marks_sum += course[top].marks[i];
        }
    }

    if (fin.eof())
        cout << "Файл прочитан до конца. ";
    else // top == n
        cout << "Данные успешно прочитаны. ";
    cout << "Количество записей = " << top << '.' << endl << endl;
    n = top;

    fin.close();





    char op;
    cout << "Желаете вывести данные на экран? [y/n]" << endl << "> ";
    cin >> op;
    assert((op == 'y' or op == 'n') and "Ошибка: введён некорректный ответ на запрос вывода данных на экран.");
    if (op == 'y')
        for (int i = 0; i < n; ++i) {
            cout << course[i].last_name << ' '
                 << course[i].first_name << ' '
                 << course[i].patronymic << ' '
                 << course[i].group << ' ';
            for (int j = 0; j < __SUBJECTS_AMOUNT; ++j)
                cout << course[i].marks[j] << ' ';
            cout << endl;
        }
    cout << endl;





    int k;
    cout << "Введите номер группы для последующего анализа результатов её студентов:" << endl
         << "> ";
    cin >> k;
    cout << endl;
    
    int kth_group_size = 0;
    for (int i = 0; i < n; ++i)
        if (course[i].group == k)
            ++kth_group_size;
    if (not kth_group_size) {
        cout << "Группы с номером " << k << " нет." << endl;
        return 0;
    }

    Stud* kth_group = new Stud[kth_group_size];
    assert(kth_group and "Ошибка: не удалось выделить память под студентов указанной группы.");
    for (int i = 0, j = 0; i < n; ++i)
        if (course[i].group == k)
            kth_group[j++] = course[i];
    
    sort(kth_group, kth_group + kth_group_size, marks_sum_desc_cmp);

    cout << "Студенты группы " << k << " в порядке убывания суммы баллов за 3 экзамена:" << endl;
    for (int i = 0; i < kth_group_size; ++i)
        cout << i + 1 << ") "
             << kth_group[i].last_name << ' '
             << kth_group[i].first_name << ' '
             << kth_group[i].marks_sum << endl;





    delete[] course;
    delete[] kth_group;
    return 0;
}

bool marks_sum_desc_cmp(Stud s1, Stud s2) {
    return s1.marks_sum > s2.marks_sum;
}
