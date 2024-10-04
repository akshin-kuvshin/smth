#include <iostream>
using namespace std;

const int N_max = 1e6;

int N,
	A[N_max + 5],
	inversions;
int tmp[N_max + 5];

int inversions_amount(int*, int, int, int*);

int main() {
	// Input
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	inversions = inversions_amount(A, 0, N, tmp);
	
	cout << inversions << '\n';
	return 0;
}


int inversions_amount(int *arr, int begin, int end, int *buffer) {
	if (end - begin <= 1)
		return 0;
	
	int answer = 0;
	int mid = (begin + end) / 2;
	
	answer += inversions_amount(arr, begin, mid, buffer);
	answer += inversions_amount(arr, mid, end, buffer);
	
	for (int k = begin; k < end; ++k)
		buffer[k] = arr[k];
	
	int left_size = mid - begin;
	int i = begin,
		j = mid,
		top = begin;
	while (i < mid or j < end) {
		if (i == mid) {
			while (j != end)
				arr[top++] = buffer[j++];
			continue;
		} else if (j == end) {
			// Логично здесь на каждой итерации цикла while уменьшать left_size на единицу,
			// но это лишние действия, т.к. после работы этого цикла while внешний цикл
			// уже прекратит свою работу => новых инверсий обнаружено не будет.
			while (i != mid)
				arr[top++] = buffer[i++];
			continue;
		}
		
		if (buffer[i] <= buffer[j]) {
			arr[top++] = buffer[i++];
			--left_size;
		} else { // buffer[i] > buffer[j]
			arr[top++] = buffer[j++];
			answer += left_size;
		}
	}
		
	return answer;
}
