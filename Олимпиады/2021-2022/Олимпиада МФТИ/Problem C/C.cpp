#include <iostream>
#include <string>
#define NOT_DEFINED -1
using namespace std;

// Constants
const int LETTERS_AMOUNT = 26;

// Variables
int N,
	letters_in_start[LETTERS_AMOUNT + 5],
	letters_in_finish[LETTERS_AMOUNT + 5],
	answer = NOT_DEFINED;
string start,
	   finish;

// Functions
void input();
void solution();
void output();
void get_letters_amount(string&, int*);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> start >> N >> finish;
	return;
}

void solution() {
	get_letters_amount(start, letters_in_start);
	
	for (int i = 0; i < LETTERS_AMOUNT; ++i)
		letters_in_start[i] *= N;
	
	get_letters_amount(finish, letters_in_finish);
	
	for (int i = 0; i < LETTERS_AMOUNT; ++i) {
		if (!letters_in_finish[i])
			continue;
		answer = ( (answer == NOT_DEFINED) ? (letters_in_start[i] / letters_in_finish[i]) : min(answer, letters_in_start[i] / letters_in_finish[i]) );
	}
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

void get_letters_amount(string &S, int *counters) {
	char C = S[0];
	int amount = NOT_DEFINED;
	
	int sz = S.size();
	for (int i = 1; i < sz; ++i) {
		if ( ('A' <= S[i]) and (S[i] <= 'Z') ) {
			if (amount == NOT_DEFINED)
				++counters[C - 'A'];
			else
				counters[C - 'A'] += amount;
			
			C = S[i];
			amount = NOT_DEFINED;
		} else
			amount = ( (amount == NOT_DEFINED) ? (S[i] - '0') : (amount * 10 + (S[i] - '0') ) );
	}
	
	if (amount == NOT_DEFINED)
		++counters[C - 'A'];
	else
		counters[C - 'A'] += amount;
	
	return;
}
