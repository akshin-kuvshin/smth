// ÷ифрова€ сортировка работает только дл€ неотрицательных чисел.
// „тобы распространить еЄ и на отрицательные - нужно выбрать некоторую константу K,
// после прибавлени€ которой ко всем элементам массива, они станут неотрицательными
// (как вариант: K = -min(array)). «атем нужно отсортировать уже изменЄнный массив,
// а в конце отн€ть эту самую константу K.

// Is it genius??? No. It is motherfucker algorithms and data structures (magic).

#include <iostream>
using namespace std;

const int N_max = 1e6,
		  MAX_ELEMENT = 1e9;

int N,
	A[N_max + 5];

void gachi_sort(int*, int);
void radix_sort(int*, int, int);

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	gachi_sort(A, N);
	
	for (int i = 0; i < N; ++i)
		cout << A[i] << ' ';
	cout << '\n';
	return 0;
}

void gachi_sort(int *arr, int sz) {
	int ten_power = 1;
	for (int i = 0; i < 9; ++i) {
		radix_sort(arr, sz, ten_power);
		ten_power *= 10;
	}
	return;
}

void radix_sort(int *arr, int sz, int ten_power) {
	int cnt[10];
	for (int i = 0; i < 10; ++i)
		cnt[i] = 0;
	
	for (int i = 0; i < sz; ++i)
		++cnt[(arr[i] / ten_power) % 10];
	
	int ind[10];
	ind[0] = 0;
	for (int i = 1; i < 10; ++i)
		ind[i] = ind[i - 1] + cnt[i - 1];
	
	int tmp[sz];
	for (int i = 0; i < sz; ++i)
		tmp[ind[(arr[i] / ten_power) % 10]++] = arr[i];
	
	for (int i = 0; i < sz; ++i)
		arr[i] = tmp[i];
	
	return;
}
