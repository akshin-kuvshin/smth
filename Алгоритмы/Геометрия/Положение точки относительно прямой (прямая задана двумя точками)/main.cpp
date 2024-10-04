#include <iostream>
#define x first
#define y second
using namespace std;

// Variables
int cr_pr;
pair <int, int> A, B, C, AB, AC;

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
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	return;
}

void solution() {
	if ( (A.x > B.x) or ( (A.x == B.x) and (A.y > B.y) ) )
		swap(A, B);
	
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	AC.x = C.x - A.x;
	AC.y = C.y - A.y;
	
	cr_pr = AB.x * AC.y - AB.y * AC.x;
	
	return;
}

void output() {
	if (cr_pr > 0)
		cout << "C > L";
	else if (cr_pr == 0)
		cout << "C = L";
	else
		cout << "C < L";
	cout << '\n';
	
	return;
}
