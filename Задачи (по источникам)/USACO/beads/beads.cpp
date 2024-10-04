/*
ID: daksion2
TASK: beads
LANG: C++
*/

//#include <iostream>
#include <fstream>
////#define fin cin
////#define fout cout
using namespace std;

// Constants
const int N_max = 350;

// Variables
int N,
	right_end,
	tmp_ans,
	answer;
char beads[N_max + 5],
	 _this;
bool used[N_max + 5],
	 flag;

// Functions
void input();
void solution();
void output();
int index(int);
char _at(int);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	ifstream fin("beads.in");
	
	fin >> N;
	for (int i = 0; i < N; ++i)
		fin >> beads[i];
	
	fin.close();
	return;
}

void solution() {
	for (int i = 0; i < N; ++i) {
		if (used[i])
			continue;
		
		used[i] = true;
		tmp_ans = 1;
		_this = beads[i];
		flag = false;
		right_end = i;
		
		if (_this == 'w')
			flag = true;
		
		for (int j = i + 1; index(j) != i; ++j) {
			if (_at(j) == _at(j - 1))
				used[j] = true;
			
			right_end = index(j);
			
			if (flag)
				if (_at(j) == 'w')
					++tmp_ans;
				else {
					++tmp_ans;
					_this = _at(j);
					flag = false;
				}
			else
				if (_at(j) == _this)
					++tmp_ans;
				else if (_at(j) == 'w')
					++tmp_ans;
				else {
					--right_end;
					break;
				}
		}
		
		_this = _at(i - 1);
		flag = false;
		
		if (_this == 'w')
			flag = true;
		
		for (int j = index(i - 1); j != right_end; j = index(j - 1)) {
			if (flag)
				if (_at(j) == 'w')
					++tmp_ans;
				else {
					++tmp_ans;
					_this = _at(j);
					flag = false;
				}
			else
				if (_at(j) == _this)
					++tmp_ans;
				else if (_at(j) == 'w')
					++tmp_ans;
				else
					break;
		}
		
		answer = max(answer, tmp_ans);
	}
	
	return;
}

void output() {
	ofstream fout("beads.out");
	fout << answer << '\n';
	fout.close();
	return;
}

int index(int attempt) {
	if (attempt < 0) return N + attempt;
	if ( (attempt >= 0) and (attempt < N) ) return attempt;
	return attempt % N;
}

char _at(int _ind) {
	return beads[index(_ind)];
}
