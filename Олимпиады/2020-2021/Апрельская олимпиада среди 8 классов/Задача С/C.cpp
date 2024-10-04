#include <fstream>
using namespace std;

// Constants
const int N_max = 1e6;

// Variables
int N,
    l,
	r,
	l_tmp,
	r_tmp,
	maxLength,
	factLength;
long long array[N_max + 5];
bool isSequence;

// Streams
ifstream fin("d.in");
ofstream fout("d.out");

// Functions
void arrayInput() {
	for (int i = 0; i < N; i++)
		fin >> array[i];
}

void maxIncreasingSequence() {
	for (int i = 0; i < N - 1; i++) {
		if (isSequence) {
			if (array[i] < array[i + 1]) {
				r_tmp++;
				factLength++;
			} else {
				if (maxLength < factLength) {
					l = l_tmp;
					r = r_tmp;
					maxLength = factLength;
				}
				isSequence = false;
			}
		} else if (array[i] < array[i + 1]) {
			l_tmp = i;
			r_tmp = l_tmp + 1;
			factLength = 2;

			isSequence = true;
		}
	}

	if (maxLength < factLength) {
		l = l_tmp;
		r = r_tmp;
		maxLength = factLength;
	}

	l++;
	r++;
}

int main() {
	// Input
	fin >> N;
	arrayInput();

	// Algorithm
	maxIncreasingSequence();

	// Output
	fout << l << ' ' << r << '\n';

	return 0;
}
