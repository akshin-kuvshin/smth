/*
ID: daksion2
TASK: milk
LANG: C++
*/

//#include <iostream>
#include <fstream>
#include <algorithm>
//#define fin cin
//#define fout cout
#define price first
#define amount second
using namespace std;

// Constants
const int M_max = 5e3;

// Variables
int N,
	M,
	answer;
pair<int, int> farmers[M_max + 5];

// Functions
void input();
void solution();
void output();

int main() {
    input();
    solution();
    output();
    
    return 0;
}

void input() {
	ifstream fin("milk.in");
	
    fin >> N >> M;
    for (int i = 0; i < M; ++i)
    	fin >> farmers[i].price >> farmers[i].amount;
    
    fin.close();
    return;
}

void solution() {
    sort(farmers, farmers + M);
    
    for (pair<int, int> *f = farmers; N; ++f)
    	if (f->amount <= N) {
    		answer += f->price * f->amount;
    		N -= f->amount;
		} else {
			answer += f->price * N;
			N = 0;
		}
	
    return;
}

void output() {
	ofstream fout("milk.out");
    fout << answer << '\n';   
	fout.close(); 
    return;
}
