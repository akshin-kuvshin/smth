#include <iostream>
using namespace std;

// Variables
int N;

// Functions
void input();
void solution_and_output();
bool isPossible(int);

int main() {
    input();
    solution_and_output();
    return 0;
}

void input() {
    cin >> N;
    return;
}

void solution_and_output() {
    if (isPossible(1))
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}

bool isPossible(int number) {
	if (number > N)
		return false;
    if ( (number == N) or (number + 3 == N) or (number + 5 == N) )
        return true;
    if (isPossible(number + 3))
    	return true;
    if (isPossible(number + 5))
    	return true;
    return false;
}
