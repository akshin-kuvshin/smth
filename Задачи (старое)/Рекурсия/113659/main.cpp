#include <iostream>
#define number first
#define answer second
#define indexInArray second

using namespace std;

// Constants
const int Nmax = 1e3;

// Variables
int _size,
	deletingMessage,
	answer;
pair<int, int> A[Nmax];

// Functions
void input();
void solution();
void output();
int findDeletedMessagesAmount(pair<int, int>*, int, int);
pair<int, int> findNextLevel(pair<int, int>*, int, int, int);
int findNextLevelsAmount(pair<int, int>*, int, int);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> _size;
	for (int i = 0; i < _size; i++)
		cin >> A[i].number >> A[i].answer;
	cin >> deletingMessage;
	
	return;
}

void solution() {
	answer = findDeletedMessagesAmount(A, _size, deletingMessage);
	return;
}

void output() {
	cout << answer << '\n';	
	return;
}

int findDeletedMessagesAmount(pair<int, int> *_array, int _sz, int deleting) {
	int deletedMessagesAmount = 1,
		nextLevelsAmount = findNextLevelsAmount(_array, _sz, deleting);
	pair<int, int> nextLevel = make_pair(0, -1);
	
	for (int i = 0; i < nextLevelsAmount; i++) {
		nextLevel = findNextLevel(_array, _sz, nextLevel.indexInArray + 1, deleting);
		deletedMessagesAmount += findDeletedMessagesAmount(_array, _sz, nextLevel.number);
	}
	
	return deletedMessagesAmount;
}

pair<int, int> findNextLevel(pair<int, int> *_array, int _sz, int start, int finding) {
	for (int i = start; i < _sz; i++)
		if (_array[i].answer == finding)
			return make_pair(_array[i].number, i);
}

int findNextLevelsAmount(pair<int, int> *_array, int _sz, int finding) {
	int nextLevelsAmount = 0;
	for (int i = 0; i < _sz; i++)
		if (_array[i].answer == finding)
			nextLevelsAmount++;
	return nextLevelsAmount;
}
