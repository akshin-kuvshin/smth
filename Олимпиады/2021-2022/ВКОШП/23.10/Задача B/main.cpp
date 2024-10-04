#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Constants
const int n_max = 1e6;

// Variables
int n,
	k,
	indexes[n_max + 5],
	reverse_indexes[n_max + 5],
	palindroms_amount,
	special_palindrom = -1,
	answer_check;
string S[n_max + 5],
	   reverse_S[n_max + 5];
pair<int, int> palindroms[n_max + 5];
bool isUsed[n_max + 5];

// Functions
void input();
void solution();
void output();
void stringSort(string*, int*, int*, int, int);
bool compareStrings(string&, string&, int);
bool reverseCompareStrings(string&, string&, int);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> S[i];
	return;
}

void solution() {
	for (int i = 0; i < n; i++)
		indexes[i] = reverse_indexes[i] = i;
	
	stringSort(S, indexes, reverse_indexes, n, k);
	
	for (int i = 0; i < n; i++) {
		if (isUsed[indexes[i]] and isUsed[reverse_indexes[i]])
			continue;
		if (isUsed[indexes[i]] or isUsed[reverse_indexes[i]])
			break;
		
		if ( (indexes[i] == reverse_indexes[i]) and (n % 2 == 1) ) {
			isUsed[indexes[i]] = true;
			
			special_palindrom = indexes[i];
			answer_check++;
		} else {
			isUsed[indexes[i]] = true;
			isUsed[reverse_indexes[i]] = true;
			
			palindroms[palindroms_amount].first = indexes[i];
			palindroms[palindroms_amount].second = reverse_indexes[i];
			palindroms_amount++;
			
			answer_check += 2;
		}
	}
	
	return;
}

void output() {
	if (answer_check == n) {
		for (int i = 0; i < palindroms_amount; i++)
			cout << palindroms[i].first + 1 << ' ';
		
		if (special_palindrom != -1)
			cout << special_palindrom + 1 << ' ';
		
		for (int i = palindroms_amount - 1; i >= 0; i--)
			cout << palindroms[i].second + 1 << ' ';
	} else
		cout << -1 << ' ';
	
	cout << '\n';
	
	return; 
}

void stringSort(string *_array, int *ind, int *rev_ind, int array_size, int string_size) {
	int j;
	for (int i = 1; i < n; i++) {
		j = i;
		while (compareStrings(_array[ind[j - 1]], _array[ind[j]], string_size) and j) {
			swap(ind[j - 1], ind[j]);
			j--;
		}
		
		j = i;
		while (reverseCompareStrings(_array[rev_ind[j - 1]], _array[rev_ind[j]], string_size) and j) {
			swap(rev_ind[j - 1], rev_ind[j]);
			j--;
		}
	}
	return;
}

bool compareStrings(string &S1, string &S2, int _size) {
	for (int i = 0; i < _size; i++)
		if (S1[i] > S2[i])
			return true;
		else if (S1[i] < S2[i])
			return false;
	return false;
}

bool reverseCompareStrings(string &S1, string &S2, int _size) {
	for (int i = _size - 1; i >= 0; i--)
		if (S1[i] > S2[i])
			return true;
		else if (S1[i] < S2[i])
			return false;
	return true;
}
