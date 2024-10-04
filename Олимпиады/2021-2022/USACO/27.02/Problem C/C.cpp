#include <iostream>
#include <string>
using namespace std;

// Constants
const int cubes_number = 4,
		  cube_size = 6,
		  N_max = 1e1,
		  word_max_size = 4;

// Variables
int N,
	_sz;
string words[N_max + 5];
bool _ans,
	 answers[N_max + 5],
	 used[cubes_number + 5];
char cubes[cubes_number + 5][cube_size + 5];

// Functions
void input();
void solution();
void output();
void get_answer(string&, int);
void make_data_null();
bool _search(int, char);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N;	
	for (int i = 0; i < cubes_number; ++i)
		for (int j = 0; j < cube_size; ++j)
			cin >> cubes[i][j];	
	for (int i = 0; i < N; ++i)
		cin >> words[i];
	return;
}

void solution() {
	for (int i = 0; i < N; ++i) {
		make_data_null();
		_sz = words[i].size();
		get_answer(words[i], 0);
		answers[i] = _ans;
	}
	return;
}

void output() {
	for (int i = 0; i < N; ++i)
		cout << (answers[i] ? "YES" : "NO") << '\n';
	return;
}

void get_answer(string &S, int ind) {
	if (_ans) return;
	
	if (ind == _sz) {
		_ans = true;
		return;
	}
	
	for (int i = 0; (i < cubes_number) and !_ans; ++i) {
		if (used[i])
			continue;
		
		if (_search(i, S[ind])) {
			used[i] = true;
			get_answer(S, ind + 1);
			used[i] = false;
		}
	}
	
	return;
}

void make_data_null() {
	for (int i = 0; i < cubes_number; ++i)
		used[i] = false;
	_ans = 0;
	return;
}

bool _search(int ind, char C) {
	for (int i = 0; i < cube_size; ++i)
		if (cubes[ind][i] == C)
			return true;
	return false;
}
