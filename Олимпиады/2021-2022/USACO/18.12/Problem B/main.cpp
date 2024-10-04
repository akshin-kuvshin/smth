#include <iostream>
#define TO_REDUCE -1
#define TO_INCREASE 1
using namespace std;

// Constants
const int N_max = 1e5;

// Variables
int N,
	p[N_max + 5],
	t[N_max + 5],
	commands_amount,
	L,
	R,
	delta;

// Functions
int _abs(int num) {
	if (num >= 0)
		return num;
	return -num;
}

bool get_L() { // true == конец программы | false == продолжаем работать
	if (p[L] != t[L])
		return false;
	
	while (p[L] == t[L]) {
		L++;
		if (L > R)
			return true;
	}
	
	return false;
}

bool get_R() { // true == конец программы | false == продолжаем работать
	if (p[R] != t[R])
		return false;
	
	while (p[R] == t[R]) {
		R--;
		if (L > R)
			return true;
	}
	
	return false;
}

int what_is_profitable() {
	int biggers = 0,
		fewers = 0;
	for (int i = L + 1; i < R; i++)
		if (p[i] < t[i])
			biggers++;
		else if (p[i] > t[i])
			fewers++;
	
	if (biggers < fewers)
		return TO_INCREASE;
	return TO_REDUCE;
}

void change_by_L(bool sign) {
	if (sign) {
		delta = _abs(p[L] - t[L]);
		for (int i = L; i <= R; i++)
			t[i] += delta;
		commands_amount += delta;
	} else {
		delta = _abs(p[L] - t[L]);
		for (int i = L; i <= R; i++)
			t[i] -= delta;
		commands_amount += delta;
	}
}

void change_by_R(bool sign) {
	if (sign) {
		delta = _abs(p[R] - t[R]);
		for (int i = L; i <= R; i++)
			t[i] += delta;
		commands_amount += delta;
	} else {
		delta = _abs(p[R] - t[R]);
		for (int i = L; i <= R; i++)
			t[i] -= delta;
		commands_amount += delta;
	}
}

void change(bool sign) {
	if (sign) {
		delta = max(_abs(p[L] - t[L]),
					_abs(p[R] - t[R]));
		for (int i = L; i <= R; i++)
			t[i] += delta;
		commands_amount += delta;
	} else {
		delta = max(_abs(p[L] - t[L]),
					_abs(p[R] - t[R]));
		for (int i = L; i <= R; i++)
			t[i] -= delta;
		commands_amount += delta;
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> p[i];
	for (int i = 0; i < N; i++)
		cin >> t[i];
	return;
}

void solution() {
	// Start valuables
	L = 0;
	R = N - 1;
	
	// Algorithm
	while (true) {
		if (get_L() or get_R())
			break;
		
		if ( (p[L] < t[L]) and (p[R] < t[R]) ) {
			change(false);
		} else if ( (p[L] > t[L]) and (p[R] > t[R]) ) {
			change(true);
		} else if ( (p[L] < t[L]) and (p[R] > t[R]) ) {
			int temp_L = L,
				temp_R = R;
			
			for (int i = L + 1; i <= R; i++)
				if (p[i] > t[i]) {
					temp_L = i;
					break;
				}
			for (int i = R - 1; i >= L; i--)
				if (p[i] < t[i]) {
					temp_R = i;
					break;
				}
			
			if (R - temp_L < temp_R - L) { // ориентируемся по левой границе
				delta = _abs(p[L] - t[L]);
				for (int i = L; i <= temp_R; i++)
					t[i] -= delta;
				commands_amount += delta;
			} else { // ориентируемся по правой границе
				delta = _abs(p[R] - t[R]);
				for (int i = temp_L; i <= R; i++)
					t[i] += delta;
				commands_amount += delta;
			}
		} else { // (p[L] > t[L]) and (p[R] < t[R])
			int temp_L = L,
				temp_R = R;
			
			for (int i = L + 1; i <= R; i++)
				if (p[i] > t[i]) {
					temp_L = i;
					break;
				}
			for (int i = R - 1; i >= L; i--)
				if (p[i] < t[i]) {
					temp_R = i;
					break;
				}
			
			if (R - temp_L < temp_R - L) { // ориентируемся по левой границе
				delta = _abs(p[L] - t[L]);
				for (int i = L; i <= temp_R; i++)
					t[i] += delta;
				commands_amount += delta;
			} else { // ориентируемся по правой границе
				delta = _abs(p[R] - t[R]);
				for (int i = temp_L; i <= R; i++)
					t[i] -= delta;
				commands_amount += delta;
			}
		}
	}
	
	return;
}

void output() {
	cout << commands_amount << '\n';
	return;
}

int main() {
	input();
	solution();
	output();
	
	return 0;
}
