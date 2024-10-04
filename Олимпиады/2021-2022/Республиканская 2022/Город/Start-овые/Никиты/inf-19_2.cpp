#include <iostream>
using namespace std;
 
int x, y, z, a, b, c;
 
void input() {
	cin >> x >> y >> z;
}
 
void sol() {
	for (int a = 1; a <= x; a++) {
		if (x % a == 0) {
			b = x / a;
			if (y % b == 0) {
				c = y / b;
				if (a * c == z) {
					cout << a << " " << b << " " << c << "\n";
					break;
				}
			}
		}
	}
}
 
int main() {
	input();
	sol();
	return 0;
}