#include <iostream>
#define WIN 1
#define DRAWN 0
#define LOSE -1
using namespace std;

// Constants
const int T_max = 10,
		  sides = 4,
		  side_min = 1,
		  side_max = 10;

// Variables
int T,
	A[sides + 5],
	B[sides + 5],
	C[sides + 5],
	input_compare,
	compare_with_A,
	compare_with_B;
bool _ans,
	 answers[T_max + 5];

// Functions
int compare(int *dice1, int *dice2) { // ответы относительно dice1
	int dice1_wins = 0,
		dice2_wins = 0;
	
	for (int i = 0; i < sides; ++i)
		for (int j = 0; j < sides; ++j)
			if (dice1[i] > dice2[j])
				++dice1_wins;
			else if (dice1[i] < dice2[j])
				++dice2_wins;
	
	if (dice1_wins > dice2_wins)
		return WIN;
	else if (dice1_wins == dice2_wins)
		return DRAWN;
	return LOSE;
}

void swap_dices(int *dice1, int *dice2) {
	for (int i = 0; i < sides; ++i)
		swap(dice1[i], dice2[i]);
	return;
}

void fill_C() {
	for (int i = 0; i < sides; ++i)
		C[i] = side_min;
	return;
}

bool check_C_for_last() {
	for (int i = 0; i < sides; ++i)
		if (C[i] != side_max)
			return false;
	return true;
}

void get_next_C() {
	++C[sides - 1];
	
	for (int i = sides - 1; i > 0; --i)
		if (C[i] > side_max) {
			C[i] = side_min;
			++C[i - 1];
		}
	
	return;
}

bool find_correct_C() {
	compare_with_A = compare(C, A); // нужно, чтобы было WIN
	compare_with_B = compare(B, C); // нужно, чтобы было WIN
	
	if ( (compare_with_A == WIN) and (compare_with_B == WIN) )
		return true;
	
	if (check_C_for_last())
		return false;
	
	get_next_C();
	
	return find_correct_C();
}

void input() {
	for (int i = 0; i < sides; ++i)
		cin >> A[i];
	for (int i = 0; i < sides; ++i)
		cin >> B[i];
	return;
}

void solution() {
	input_compare = compare(A, B);
	
	if (input_compare == DRAWN) {
		_ans = false;
		return;
	} else if (input_compare == LOSE)
		swap_dices(A, B);
	
	fill_C();
	_ans = find_correct_C();
	
	return;
}

void output(int index) {
	answers[index] = _ans;
	return;
}

int main() {
	// Input
	cin >> T;
	
	// Solution
	for (int _t = 0; _t < T; ++_t) {
		input();
		solution();
		output(_t);
	}
	
	// Output
	for (int _t = 0; _t < T; ++_t)
		cout << (answers[_t] ? "yes" : "no") << '\n';
	
	return 0;
}

