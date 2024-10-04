/*
ID: daksion2
TASK: dualpal
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
ofstream fout("dualpal.out");

// Variables
int N,
	S,
	founded;
char additional_digits[15] = "ABCDEFGHIJKLMN";
string converted_num;

// Functions
void input();
void solution();
int check(int);
string convert(int, int);
bool is_palindrom(string&);

int main() {
    input();
    solution();
    
    return 0;
}

void input() {
	ifstream fin("dualpal.in");
    fin >> N >> S;
    fin.close();
    
    return;
}

void solution() {
    for (int i = S + 1; founded < N; ++i)
    	founded += check(i);    
    return;
}

int check(int num) {
	int counter = 0;
	for (int base = 2; base <= 10; ++base) {
		converted_num = convert(num, base);
		if (is_palindrom(converted_num))
			++counter;
	}
	
	if (counter >= 2) {
		fout << num << '\n';
		return 1;
	}
	
	return 0;
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
