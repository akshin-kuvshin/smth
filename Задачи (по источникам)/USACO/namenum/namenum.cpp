/*
ID: daksion2
TASK: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#define fin cin
//#define fout cout
using namespace std;

// Streams
ofstream fout("namenum.out");

// Constants
const int dict_size_max = 5e3,
		  digits_amount = 10,
		  letters_in_digit_amount = 3,
		  name_size_max = 12;

// Variables
long long N;
int dict_size,
	num_size,
	attempt_size,
	mid,
	counter;
string dict[dict_size_max + 5],
	   attempt;
char letters[digits_amount + 5][letters_in_digit_amount + 5] = {"",
																"",
																"ABC",
																"DEF",
													    		"GHI",
													    		"JKL",
															    "MNO",
															    "PRS",
															    "TUV",
															    "WXY"};
vector<int> num;

// Functions
void input();
void solution();
void separate_N();
void dfs(int);
void search();
bool binary_search(int, int);

int main() {
    input();
    solution();
    
    return 0;
}

void input() {
    ifstream dict_input("dict.txt");
    while (!dict_input.eof())
		dict_input >> dict[dict_size++];
    dict_input.close();
    
    ifstream fin("namenum.in");
    fin >> N;
    fin.close();
    return;
}

void solution() {
    separate_N();
	dfs(0);
    
    if (!counter)
    	fout << "NONE" << '\n';
    fout.close();
    
    return;
}

void separate_N() {
	while (N) {
		num.insert(num.begin(), N % 10);
		N /= 10;
	}
	num_size = num.size();
	return;
}

void dfs(int index) {
	if (index == num_size) {
		search();
		return;
	}
	
	attempt.push_back(' ');
	++attempt_size;
	for (int i = 0; i < letters_in_digit_amount; ++i) {
		attempt[attempt_size - 1] = letters[num[index]][i];
		dfs(index + 1);
	}
	attempt.pop_back();
	--attempt_size;
	
	return;
}

void search() {
	if (binary_search(0, dict_size - 1)) {
		fout << attempt << '\n';
		++counter;
	}
	return;
}

bool binary_search(int L, int R) {
	if (L > R)
		return false;
	
	mid = (L + R) / 2;
	if (attempt == dict[mid])
		return true;
	if (attempt < dict[mid])
		return binary_search(L, mid - 1);
	return binary_search(mid + 1, R);
}
