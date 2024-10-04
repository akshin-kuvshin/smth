// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

// bool check(const vector<vector<lli>>&, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	lli N;
	cin >> N;
	
	if (N < 3LL) {
		cout << "NO\n";
		return 0;
	}
	
	vector<vector<lli>> A(2LL * N, vector<lli>(2LL * N));
	
	for (int i = 0; i < (int)N; ++i)
		A[0][i] = 1LL;
	for (int i = (int)N; i < 2 * (int)N; ++i)
		A[0][i] = 0LL;
	
	for (int i = 1, shift = 2; i < (int)N; ++i, shift += 2)
		for (int j = 0; j < 2 * (int)N; ++j)
			A[i][j] = A[0][(j + shift) % (2 * (int)N)];
	for (int i = (int)N, shift = 1; i < 2 * (int)N; ++i, shift += 2)
		for (int j = 0; j < 2 * (int)N; ++j)
			A[i][j] = A[0][(j + shift) % (2 * (int)N)];
	
	cout << "YES\n";
	for (auto row : A) {
		for (auto elem : row)
			cout << elem << ' ';
		cout << '\n';
	}
			
	return 0;
}

/* bool check(const vector<vector<lli>> &A, lli N) {
	for (int i = 0; i < 2 * (int)N; ++i) {
		lli row_sum = 0LL,
			col_sum = 0LL;
		for (int j = 0; j < 2 * (int)N; ++j) {
			row_sum += A[i][j];
			col_sum += A[j][i];
		}
		if (col_sum != N or row_sum != N)
			return false;
	}
	
	for (int i = 0; i < 2 * (int)N; ++i)
		for (int j = i + 1; j < 2 * (int)N; ++j) {
			bool flag1 = false,
				 flag2 = false;
			for (int x = 0; x < 2 * (int)N; ++x) {
				if (A[i][x] != A[j][x])
					flag1 = true;
				if (A[x][i] != A[x][j])
					flag2 = true;
			}
			if (!flag1 or !flag2)
				return false;
		}
	
	for (int i = 0; i < 2 * (int)N; ++i)
		for (int j = 0; j < 2 * (int)N; ++j) {
			bool flag = false;
			for (int x = 0; x < 2 * (int)N; ++x)
				if (A[i][x] != A[x][j])
					flag = true;
			if (!flag)
				return false;
		}
	
	return true;
} */
