#include <fstream>
using namespace std;

// Constants
const int maxSize = 1e6, noSolution = -1;

// Variables (N = size, A = finding, B = changing, C = enteringString)
int size;
char finding, changing, enteringString[maxSize + 5];

// Streams
ifstream fin("a.in");
ofstream fout("a.out");

// Functions
void changeSymbols() {
	for (int i = 0; i < size; i++)
		if ( (enteringString[i] == finding) || (enteringString[i] == finding - 32) )
			enteringString[i] = changing;
}

int main() {
	// Input
	fin >> finding >> changing >> enteringString;
	size = sizeof(enteringString) / sizeof(char);
	
	if (size > maxSize) {
		// No solution case
		fout << noSolution << '\n';
	} else {
		// Algorithm
		changeSymbols();
		
		// Output
		fout << size << '\n' << enteringString << '\n';
	}
	
	return 0;
}
