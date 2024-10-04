#include <fstream>
using namespace std;

// Constants
const int N_max = 1e6;

// Variables
long long N,
          k,
          P,
          A,
          pows[N_max + 5];

// Streams
ifstream fin("c.in");
ofstream fout("c.out");

// Functions
void powsFilling() {
	pows[0] = 1;
	for (int i = 1; i <= N; i++)
		pows[i] = ( (pows[i - 1] % P) * (k % P) ) % P;
}

void powsSumming() {
	for (int i = 0; i <= N; i++)
		A = ( (A % P) + (pows[i] % P) ) % P;
}

int main() {
	// Input
	fin >> N >> k >> P;
	
	// Algorithm
	powsFilling();
	powsSumming();
	
	// Output
	fout << A << '\n';
	
	return 0;
}
