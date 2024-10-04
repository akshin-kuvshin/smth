#include <iostream>
#include <string>
using namespace std;

// Constants
const int N_max = 1e2,
		  numbers_amount = 2;

// Variables
int N;
string A[N_max + 5][numbers_amount + 5],
	   _ans;

// Functions
void input();
void solution();
void output();
string sum(string, string);
void reverse(string&);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N;
	return;
}

void solution() {
	// первый индекс массива A - длина последовательности (отсчёт идёт с единицы до N),
	// второй индекс - цифра, которая стоит в начале (0 или 1).
		  
	A[1][0] = A[1][1] = "1";
	for (int i = 2; i <= N; ++i) {
		A[i][0] = sum(A[i - 1][0], A[i - 1][1]);
		A[i][1] = A[i - 1][0];
	}
	_ans = sum(A[N][0], A[N][1]);
	
	return;
}

void output() {
	cout << _ans << '\n';
	return;
}

string sum(string num1, string num2) {
	reverse(num1);
	reverse(num2);
	
	if (num1.size() < num2.size()) {
		int sz1 = num1.size(),
			sz2 = num2.size();
		
		while (sz1 < sz2) {
			num1.push_back('0');
			++sz1;
		}
	} else if (num1.size() > num2.size()) {
		int sz1 = num1.size(),
			sz2 = num2.size();
		
		while (sz1 > sz2) {
			num2.push_back('0');
			++sz2;
		}
	}
	
	int tmp = 0,
		in_mind = 0,
		sz = num1.size();
	string _sum = "";
	
	for (int i = 0; i < sz; ++i) {
		tmp = num1[i] + num2[i] - 2 * '0' + in_mind;
		in_mind = tmp / 10;
		
		tmp %= 10;
		_sum.push_back(tmp + '0');
	}
	
	if (in_mind > 0)
		_sum.push_back(in_mind + '0');
	
	reverse(_sum);
	return _sum;
}

void reverse(string &S) {
	int sz = S.size();
	for (int i = 0; i < sz / 2; ++i)
		swap(S[i], S[sz - i - 1]);
	return;
}
