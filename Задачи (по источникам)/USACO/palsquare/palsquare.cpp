/*
ID: daksion2
TASK: palsquare
LANG: C++
*/

//#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define fin cin
#define fout cout
using namespace std;

// Streams
ofstream fout("palsquare.out");

// Constants
const int N_start = 1,
		  N_finish = 300;

// Variables
int base,
	square;
string converted_num,
	   converted_square;
char additional_digits[15] = "ABCDEFGHIJKLMN";

// Functions
void input();
void solution();
void check(int);
string convert(int, int);
bool is_palindrom(string&);

int main() {
    input();
    solution();
    
    return 0;
}

void input() {
    ifstream fin("palsquare.in");
    fin >> base;
    fin.close();
    
    return;
}

void solution() {
    for (int i = N_start; i <= N_finish; ++i)
    	check(i);
    return;
}

void check(int num) {
	square = num * num;
	converted_square = convert(square, base);
	
	if (is_palindrom(converted_square)) {
		converted_num = convert(num, base);
		fout << converted_num << ' ' << converted_square << '\n';
	}
	
	return;
}

string convert(int x, int b) {
	int tmp = 0;
	string answer = "";
	
	while (x) {
		tmp = x % b;
		if (tmp >= 10)
			tmp = additional_digits[tmp - 10];
		else
			tmp += '0';
		answer.push_back((char)tmp);
		
		x /= b;
	}
	
	reverse(answer.begin(), answer.end());
	return answer;
}

bool is_palindrom(string &S) {
	int sz = (int)S.size(),
		half_size = sz / 2;
	for (int i = 0; i < half_size; ++i)
		if (S[i] != S[sz - i - 1])
			return false;
	return true;
}
