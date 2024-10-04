#include <iostream>
using namespace std;

// Variables
int n;

// Functions
void input();
void solution();
void hanoi(int, int, int, int);

int main() {
	input();
	solution();

	return 0;
}

void input() {
	cin >> n;
}

void solution() {
	hanoi(1, 2, n, 1);
}

void hanoi(int from, int to, int disksAmount, int topDisk) {
	if (disksAmount == 1) {
		cout << "Disk " << topDisk << " move from " << from << " to " << to << '\n';
	} else {
		hanoi(from, 6 - from - to, disksAmount - 1, topDisk);
		hanoi(from, to, 1, disksAmount);
		hanoi(6 - from - to, to, disksAmount - 1, topDisk);
	}
}
