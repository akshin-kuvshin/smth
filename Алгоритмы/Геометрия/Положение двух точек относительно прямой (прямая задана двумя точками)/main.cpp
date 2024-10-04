#include <iostream>
#define x first
#define y second
using namespace std;

// Variables
int cr_pr_C,
	cr_pr_D;
pair <int, int> A,
				B,
				C,
				D,
				AB,
				AC,
				AD;

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
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
	return;
}

void solution() {
	if ( (A.x > B.x) or ( (A.x == B.x) and (A.y > B.y) ) )
		swap(A, B);
	
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	AC.x = C.x - A.x;
	AC.y = C.y - A.y;
	AD.x = D.x - A.x;
	AD.y = D.y - A.y;
	
	cr_pr_C = AB.x * AC.y - AB.y * AC.x;
	cr_pr_D = AB.x * AD.y - AB.y * AD.x;
	
	return;
}

void output() {
	if ( ( (cr_pr_C > 0) and (cr_pr_D > 0) ) or ( (cr_pr_C < 0) and (cr_pr_D < 0) ) )
		cout << "C and D are on same side.";	
	else if ( (cr_pr_C == 0) and (cr_pr_D == 0) )
		cout << "C and D are on straight.";
	else
		cout << "C and D are on different sides.";
	cout << '\n';
	
	return;
}
