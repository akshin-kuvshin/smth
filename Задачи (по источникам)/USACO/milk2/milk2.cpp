/*
ID: daksion2
TASK: milk2
LANG: C++
*/

//#include <iostream>
#include <fstream>
//#define fin cin
//#define fout cout
using namespace std;

// Constants
const int K_max = 1e6;

// Variables
int N,
	K_begin = K_max + 5,
	K_end,
	_begin,
	_end,
	condition,
	non_milked_tmp,
	milked_tmp,
	non_milked_max,
	milked_max,
	times[K_max + 5];
bool is_milked[K_max + 5],
	 direct,
	 _this;

// Functions
void input__part_sol();
void solution();
void output();

int main() {
	input__part_sol();
	solution();
	output();
	return 0;
}

void input__part_sol() {
	ifstream fin("milk2.in");
	
	fin >> N;
	for (int i = 0; i < N; ++i) {
		fin >> _begin >> _end;
		++times[_begin];
		--times[_end];
		
		K_begin = min(_begin, K_begin);
		K_end = max(_end, K_end);
	}
	
	fin.close();
	return;
}

void solution() {
	// Fill "is_milkes" array
	for (int i = K_begin; i <= K_end; ++i) {
		condition += times[i];
		is_milked[i] = condition;
	}
	
	direct = is_milked[K_begin];
	if (direct) ++milked_tmp;
	else ++non_milked_tmp;
	
	for (int i = K_begin + 1; i <= K_end; ++i) {
		_this = is_milked[i];
		if (_this and direct)
			++milked_tmp;
		else if (_this and !direct) {
			non_milked_max = max(non_milked_tmp, non_milked_max);
			non_milked_tmp = 0;
			milked_tmp = 1;
			direct = _this;
		} else if (!_this and direct) {
			milked_max = max(milked_tmp, milked_max);
			milked_tmp = 0;
			non_milked_tmp = 1;
			direct = _this;
		} else
			++non_milked_tmp;
	}
	
	return;
}

void output() {
	ofstream fout("milk2.out");
	fout << milked_max << ' ' << non_milked_max << '\n';
	fout.close();
	return;
}

