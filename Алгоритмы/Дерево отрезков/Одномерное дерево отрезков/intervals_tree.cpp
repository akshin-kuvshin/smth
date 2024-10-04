/* Реализация, где индексы в запросах нумеруются с единицы.
   Для верной индексации с нуля нужно увеличить индекс-сдвиг d на единицу. */

#include <iostream>
#include <string>
using namespace std;

const int N_max = 1e6;

int N,
	A[2 * N_max + 5],
	d;

int powers_of_two[20 + 5];

int Q,
	_begin,
	_end,
	index,
	value;
string S;

void set_powers_of_two(int*, int);
void set_tree(int*, int, int);
int sum(int, int);
void add(int, int);

int main() {
	// Preprocessing
	set_powers_of_two(powers_of_two, 20);
	
	// Input
	cin >> N;
	
	int ind = 0;
	while (N > powers_of_two[ind])
		++ind;
	d = powers_of_two[ind] - 1;
	
	for (int i = 1; i <= N; ++i)
		cin >> A[i + d];
	N = powers_of_two[ind];
	
	set_tree(A, d + 1, N + d + 1);
	
	// Solution + output
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> S;
		if (S == "sum") {
			cin >> _begin >> _end;
			cout << sum(_begin + d, _end + d) << '\n';
		} else if (S == "add") {
			cin >> index >> value;
			add(index, value);
			cout << "OK\n";
		} else
			cout << "error\n";
	}
	
	return 0;
}

void set_powers_of_two(int *powers, int sz) {
	powers[0] = 1;
	for (int i = 1; i <= sz; ++i)
		powers[i] = powers[i - 1] * 2;
	return;
}

void set_tree(int *tree, int b, int e) {
	if (e - b == 1)
		return;
	
	for (int i = b; i < e; i += 2)
		tree[i / 2] = tree[i] + tree[i + 1];
	set_tree(tree, b / 2, e / 2);
	return;
}

int sum(int L, int R) {
	if (L == R)
		return A[L];
	else if (L > R)
		return 0;
	
	int answer = 0;
	if (L % 2 == 1) {
		answer += A[L];
		++L;
	}
	if (R % 2 == 0) {
		answer += A[R];
		--R;
	}
	
	answer += sum(L / 2, R / 2);
	return answer;
}

void add(int i, int val) {
	i += d;
	while (i) {
		A[i] += val;
		i /= 2;
	}
	return;
}
