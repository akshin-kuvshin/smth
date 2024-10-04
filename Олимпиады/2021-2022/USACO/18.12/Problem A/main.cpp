#include <iostream>
using namespace std;

// Constants
const long long N_max = 1e6;

// Variables
long long N,
		  bad_substrings_amount,
		  G_amount,
		  H_amount,
		  first_G,
		  last_G,
		  first_H,
		  last_H,
		  _size;
char S[N_max];

// Functions
void input() {
	cin >> N >> S;
	return;
}

void solution() {
	for (int length = 3; length <= N; length++) {
		int amount = N - length;
		for (int i = 0; i <= amount; i++) {
			G_amount = H_amount = 0;
			first_G = first_H = last_G = last_H = -1;
			
			for (int j = i; j < i + length; j++) {
				if (first_G != -1 and first_H != -1)
					break;
				
				if (S[j] == 'G' and first_G == -1)
					first_G = j;
				else if (S[j] == 'H' and first_H == -1)
					first_H = j;
			}
			
			for (int j = i + length - 1; j >= i; j--) {
				if (last_G != -1 and last_H != -1)
					break;
				
				if (S[j] == 'G' and last_G == -1)
					last_G = j;
				else if (S[j] == 'H' and last_H == -1)
					last_H = j;
			}
			
			if (first_G != -1 and first_G == last_G)
				bad_substrings_amount++;
			if (first_H != -1 and first_H == last_H)
				bad_substrings_amount++;
		}
	}
	return;
}

void output() {
	cout << bad_substrings_amount << '\n';
	return;
}

int main() {
	input();
	solution();
	output();
	
	return 0;
}
