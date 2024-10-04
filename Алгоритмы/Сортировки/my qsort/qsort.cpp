#include <iostream>
using namespace std;

const int N_max = 1e6;

int N,
    A[N_max + 5];

void quick_sort(int*, int, int);

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    quick_sort(A, 0, N);

    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';
    cout << '\n';

    return 0;
}

void quick_sort(int *arr, int begin, int end) {
	// Крайний случай
	if (end - begin <= 1)
		return;
	
	// Выбираем опорный элемент
    int pivot = arr[(begin + end) / 2];
    // В промежутке [m_beg; m_end) находятся опорные элементы =>
    // Их сортировать не нужно
    int m_beg = begin,
        m_end = begin;
    
    for (int i = begin; i < end; ++i)
        if (arr[i] < pivot) {
            swap(arr[i], arr[m_beg]);
            // Второй обмен не нужен, если опорных элементов ещё нет.
            // Если они есть - то вторым обменом мы возвращаем опорный элемент в стопку опорных элементов.
            if (m_beg != m_end)
            	swap(arr[i], arr[m_end]);
            ++m_beg;
            ++m_end;
        } else if (arr[i] == pivot) {
        	// Добавляем новый опорный элемент в конец стопки опорных элементов
            swap(arr[i], arr[m_end]);
            ++m_end;
        }
    
    quick_sort(arr, begin, m_beg);
    quick_sort(arr, m_end, end);

    return;
}
