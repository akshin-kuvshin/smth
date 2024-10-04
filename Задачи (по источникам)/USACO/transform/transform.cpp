/*
ID: daksion2
TASK: transform
LANG: C++
*/

//#include <iostream>
#include <fstream>
//#define fin cin
//#define fout cout
using namespace std;

// Constants
const int N_max = 1e1;

// Variables
int N,
	_ans;
char A[N_max + 5][N_max + 5],
	 B[N_max + 5][N_max + 5];

// Functions
void input();
void solution();
void output();
bool check1();
bool check2();
bool check3();
bool check4();
bool check5();
bool check6();

int main() {
    input();
    solution();
    output();
    
    return 0;
}

void input() {
    ifstream fin("transform.in");
    
    fin >> N;
    for (int i = 0; i < N; ++i)
    	for (int j = 0; j < N; ++j)
    		fin >> A[i][j];
    for (int i = 0; i < N; ++i)
    	for (int j = 0; j < N; ++j)
    		fin >> B[i][j];
    
    fin.close();
    return;
}

void solution() {
	if (check1())
    	_ans = 1;
    else if (check2())
    	_ans = 2;
    else if (check3())
    	_ans = 3;
    else if (check4())
    	_ans = 4;
    else if (check5())
    	_ans = 5;
    else if (check6())
    	_ans = 6;
    else
    	_ans = 7;
    
    return;
}

void output() {
    ofstream fout("transform.out");
    fout << _ans << '\n';    
    fout.close();
    return;
}

bool check1() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (A[i][j] != B[j][N - i - 1])
				return false;
	return true;
}

bool check2() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (A[i][j] != B[N - i - 1][N - j - 1])
				return false;
	return true;
}

bool check3() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (A[i][j] != B[N - j - 1][i])
				return false;
	return true;
}

bool check4() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (A[i][j] != B[i][N - j - 1])
				return false;
	return true;
}

bool check5() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N / 2; ++j)
			swap(A[i][j], A[i][N - j - 1]);
	
	return check1() or check2() or check3();
}

bool check6() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N / 2; ++j)
			swap(A[i][j], A[i][N - j - 1]);
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (A[i][j] != B[i][j])
				return false;
	
	return true;
}
