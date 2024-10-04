#include <iostream>
#define dot pair<int, int>
#define vect pair<int, int>
#define x first
#define y second
using namespace std;

// Variables
int S,
	cr_pr;
dot A,
	B,
	C;
vect AB,
	 AC;

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
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	return;
}

void solution() {
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	AC.x = C.x - A.x;
	AC.y = C.y - A.y;
	
	cr_pr = AB.x * AC.y - AC.x * AB.y;
	
	return;
}

void output() {
	cout << abs(cr_pr) / 2.;
	return;
}

