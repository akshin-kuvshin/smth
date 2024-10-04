#include <iostream>
using namespace std;

// Variables
int N,
	A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17},
	mid;

// Functions
int _bs(int, int);

int main() {
	cin >> N;
	cout << _bs(0, sizeof(A) / sizeof(int) - 1) << '\n';
	return 0;
}

int _bs(int L, int R) {
	if (L > R)
		return -1;

    mid = (L + R) / 2;

    if (N == A[mid])
        return mid;
	if (N < A[mid])
		return _bs(L, mid - 1);
	if (N > A[mid])
		return _bs(mid + 1, R);
}
