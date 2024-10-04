// ПыСы: в процессе действия функции nth_element меняется исходный массив.
// Чтобы избежать этого - просто скопируйте исходный массив A в дополнительный tmp_A
// и передайте в функцию указатель на него.

#include <iostream>
using namespace std;

const int N_max = 1e6;

int N,
	A[N_max + 5],
	K;

int nth_element(int*, int, int, int);

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	cin >> K;
	
	cout << nth_element(A, 0, K, N) << '\n';
	return 0;
}

// arr - массив
// begin - начало рассматриваемого отрезка
// pos - индекс искомого элемента (в уже отсортированном массиве)
// end - конец рассматриваемого отрезка (элемент после последнего)
int nth_element(int *arr, int begin, int pos, int end) {
	// В этом случае begin == pos
	if (end - begin == 1)
		return arr[begin];
	
	
	// Здесь и далее работает по принципу quick_sort,
	// не буду комментить заново - уже делал в соответствующем алгосе.
	int pivot = arr[(begin + end) / 2];
	int m_beg = begin,
		m_end = begin;
	
	for (int i = begin; i < end; ++i)
		if (arr[i] < pivot) {
			swap(arr[i], arr[m_beg]);
			if (m_beg != m_end)
				swap(arr[i], arr[m_end]);
			++m_beg;
			++m_end;
		} else if (arr[i] == pivot) {
			swap(arr[i], arr[m_end]);
			++m_end;
		}
	
	if (m_beg <= pos and pos < m_end)
		return pivot;
	if (begin <= pos and pos < m_beg)
		return nth_element(arr, begin, pos, m_beg);
	return nth_element(arr, m_end, pos, end);
}
