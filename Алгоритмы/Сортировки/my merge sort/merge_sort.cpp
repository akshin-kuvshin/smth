// К сожалению, данная реализация требует ручного выделения дополнительного
// объёма памяти для кэша (буфера, но не сиськи), который необходим для слияния
// отсортированных половинок.

#include <iostream>
using namespace std;

const int N_max = 1e5;

int N,
    A[N_max + 5],
    cache[N_max + 5];

void merge_sort(int*, int, int*);
void merge_sort(int*, int, int, int*);

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    merge_sort(A, N, cache);

    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
    return 0;
}

void merge_sort(int *arr, int sz, int *buffer) {
    merge_sort(arr, 0, sz, buffer);
    return;
}

void merge_sort(int *arr, int begin, int end ,int *buffer) {
    if (end - begin == 1) // подмассив из 1 элемента всегда является отсортированным
        return;
    
    int mid = (begin + end) / 2;

    // Сортируем два равных подмассива
    merge_sort(arr, begin, mid, buffer);
    merge_sort(arr, mid, end, buffer);

    // Копируем оба отсортированных подмассива
    for (int i = begin; i < end; ++i)
        buffer[i] = arr[i];

    // Происходит "слияние" из двух скопированных отсортированных подмассивов в исходный
    for (int i = begin, j = mid, cnt = begin; (i < mid) or (j < end); ) {
        if (i == mid) {
            while (j < end)
                arr[cnt++] = buffer[j++];
            continue;
        } else if (j == end) {
            while (i < mid)
                arr[cnt++] = buffer[i++];
            continue;
        }

        if (buffer[i] < buffer[j])
            arr[cnt++] = buffer[i++];
        else
            arr[cnt++] = buffer[j++];
    }

    return;
}
