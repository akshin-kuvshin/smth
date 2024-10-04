#include <iostream>
#include <string>
#define dot pair<int, int>
#define vect pair<int, int>
#define x first
#define y second
using namespace std;

// Variables
int res;
dot triangle[3],
	K; // точка, относительное положение которой мы ищем.
string answers[] = {"out", "on", "in"};

// Functions
void input();
void solution();
void output();
int cr_pr(dot, dot, dot, dot);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	for (int i = 0; i < 3; ++i)
		cin >> triangle[i].x >> triangle[i].y;
	cin >> K.x >> K.y;
	
	return;
}

void solution() {
	for (int i = 0; i < 3; ++i) {
		bool sign = (cr_pr(triangle[i], triangle[(i + 1) % 3], triangle[i], triangle[(i + 2) % 3]) >= 0);
		
		int cr_pr_K = cr_pr(triangle[i], triangle[(i + 1) % 3], triangle[i], K);
		if (!cr_pr_K) {
			res = 1;
			return;
		}
		else if ( (cr_pr_K >= 0) == sign)
			continue;
		
		// else
		res = 0;
		return;
	}
	
	res = 2;
	return;
}

void output() {
	cout << answers[res] << '\n';
	return;
}

int cr_pr(dot A1, dot A2, dot B1, dot B2) { // передаются начала и концы векторов.
	vect A;
	A.x = A2.x - A1.x;
	A.y = A2.y - A1.y;
	
	vect B;
	B.x = B2.x - B1.x;
	B.y = B2.y - B1.y;
	
	return A.x * B.y - B.x * A.y;
}
