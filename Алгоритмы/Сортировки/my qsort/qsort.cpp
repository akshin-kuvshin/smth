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
	// ������� ������
	if (end - begin <= 1)
		return;
	
	// �������� ������� �������
    int pivot = arr[(begin + end) / 2];
    // � ���������� [m_beg; m_end) ��������� ������� �������� =>
    // �� ����������� �� �����
    int m_beg = begin,
        m_end = begin;
    
    for (int i = begin; i < end; ++i)
        if (arr[i] < pivot) {
            swap(arr[i], arr[m_beg]);
            // ������ ����� �� �����, ���� ������� ��������� ��� ���.
            // ���� ��� ���� - �� ������ ������� �� ���������� ������� ������� � ������ ������� ���������.
            if (m_beg != m_end)
            	swap(arr[i], arr[m_end]);
            ++m_beg;
            ++m_end;
        } else if (arr[i] == pivot) {
        	// ��������� ����� ������� ������� � ����� ������ ������� ���������
            swap(arr[i], arr[m_end]);
            ++m_end;
        }
    
    quick_sort(arr, begin, m_beg);
    quick_sort(arr, m_end, end);

    return;
}
