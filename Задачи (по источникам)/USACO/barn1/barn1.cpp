/*
ID: daksion2
TASK: barn1
LANG: C++
*/

//#include <iostream>
#include <fstream>
#include <algorithm>
//#define fin cin
//#define fout cout
using namespace std;

// Constants
const int STALLS_MAX = 2e2;

// Variables
int M,
	S,
	C,
	cows[STALLS_MAX + 5],
	top,
	boards_used = 1,
	open_number,
	spaces[STALLS_MAX + 5],
	answer;
bool stalls[STALLS_MAX + 5];

// Functions
void input();
void solution();
void output();
void get_empty_spaces(int, int);

int main() {
    input();
    solution();
    output();
    
    return 0;
}

void input() {
	ifstream fin("barn1.in");
    
    fin >> M >> S >> C;
    for (int i = 0; i < C; ++i)
    	fin >> cows[i];
    
    open_number = S;
    
    fin.close();
    return;
}

// DONE
void solution() {
	// Fill stalls[]
    for (int i = 0; i < C; ++i)
    	stalls[cows[i] - 1] = true;
    
    // Fill and sort spaces[]
    int _begin = 0,
    	_end = S;
    for (int i = 0; i < S; ++i)
    	if (stalls[i]) {
    		_begin = i;
    		break;
		} else --open_number;
	for (int i = S - 1; i >= 0; --i)
		if (stalls[i]) {
			_end = i + 1;
			break;
		} else --open_number;
	
	get_empty_spaces(_begin, _end);
	sort(spaces, spaces + top);
    
    // Final
    while ( (boards_used != M) and top) {
    	open_number -= spaces[--top];
    	++boards_used;
	}
    
    answer = open_number;
    return;
}

void output() {
    ofstream fout("barn1.out");
    fout << answer << '\n';
    fout.close();    
    return;
}


void get_empty_spaces(int b, int e) {
	int tmp = 0;
	
	bool flag = false;
	for (int i = b; i < e; ++i)
		if (stalls[i] and flag) {
			spaces[top++] = tmp;
			tmp = 0;
			flag = false;
		} else if (!stalls[i] and flag)
			++tmp;
		else if (!stalls[i] and !flag) {
			tmp = 1;
			flag = true;
		}
	
	return;
}
