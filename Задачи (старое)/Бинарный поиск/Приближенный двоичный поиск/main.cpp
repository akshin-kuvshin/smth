#include <iostream>
using namespace std;

// Constants
const int Nmax = 1e5,
		  Kmax = 1e5;

// Variables
int N,
	K,
	N_array[Nmax + 5],
	K_array[Kmax + 5],
	A_array[Kmax + 5],
	mid;

// Functions
void input();
void solution();
void output();
int nearly_binary_search(int, int, int);
int ABS(int);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> N_array[i];
	for (int i = 0; i < K; i++)
		cin >> K_array[i];
	
	return;
}

void solution() {
	for (int i = 0; i < K; i++)
		A_array[i] = nearly_binary_search(0, N - 1, K_array[i]);
	return;
}

void output() {
	for (int i = 0; i < K; i++)
		cout << A_array[i] << '\n';
	
	return;
}

int nearly_binary_search(int L, int R, int finding) {
	if (L > R) {
		if (R == -1)
			return N_array[L];
		if (L == N)
			return N_array[R];
		
		int abs_for_L = ABS(finding - N_array[L]),
			abs_for_R = ABS(finding - N_array[R]);
		
		if (abs_for_L < abs_for_R)
			return N_array[L];
		return N_array[R];
	}
	
	mid = (L + R) / 2;
	
	if (finding - N_array[mid] == 0)
		return N_array[mid];
	else if (finding - N_array[mid] < 0)
		return nearly_binary_search(L, mid - 1, finding);
	return nearly_binary_search(mid + 1, R, finding);
}

int ABS(int num) {
	return ( (num >= 0) ? num : -num);
}
