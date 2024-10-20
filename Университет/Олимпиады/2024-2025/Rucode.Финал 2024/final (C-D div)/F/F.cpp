// author: Danila "akshin_" Axyonov

#include <iostream>
#include <algorithm>
using namespace std;

#define FORI            for (int i = START; i < FINISH; ++i)
#define FORJ            for (int j = START; j < FINISH; ++j)

const int MAX_SIZE = 20,
          START = 2,
          FINISH = 10;

char F[MAX_SIZE][MAX_SIZE],
     W[MAX_SIZE][MAX_SIZE],
     B[MAX_SIZE][MAX_SIZE];

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    FORI fill(W[i], W[i] + MAX_SIZE, '?');
    FORI fill(B[i], B[i] + MAX_SIZE, '?');
    solve();

    return 0;
}

void solve() {
    FORI FORJ cin >> F[i][j];

    // for white
    FORI FORJ {
        if (F[i][j] == 'k') {
            for (int k = i - 1; k <= i + 1; ++k)
                for (int l = j - 1; l <= j + 1; ++l)
                    W[k][l] = F[k][l];
        } else if (F[i][j] == 'r') {
            W[i][j] = F[i][j];
            // right
            for (int l = j + 1; l < FINISH; ++l) {
                W[i][l] = F[i][l];
                if (F[i][l] != '.')
                    break;
            }
            // left
            for (int l = j - 1; l >= START; --l) {
                W[i][l] = F[i][l];
                if (F[i][l] != '.')
                    break;
            }
            // up
            for (int k = i - 1; k >= START; --k) {
                W[k][j] = F[k][j];
                if (F[k][j] != '.')
                    break;
            }
            // down
            for (int k = i + 1; k < FINISH; ++k) {
                W[k][j] = F[k][j];
                if (F[k][j] != '.')
                    break;
            }
        } else if (F[i][j] == 'q') { // actually, q = r + b
            W[i][j] = F[i][j];

            // DA ROOOK PART
            // right
            for (int l = j + 1; l < FINISH; ++l) {
                W[i][l] = F[i][l];
                if (F[i][l] != '.')
                    break;
            }
            // left
            for (int l = j - 1; l >= START; --l) {
                W[i][l] = F[i][l];
                if (F[i][l] != '.')
                    break;
            }
            // up
            for (int k = i - 1; k >= START; --k) {
                W[k][j] = F[k][j];
                if (F[k][j] != '.')
                    break;
            }
            // down
            for (int k = i + 1; k < FINISH; ++k) {
                W[k][j] = F[k][j];
                if (F[k][j] != '.')
                    break;
            }

            // BISHOP PART
            int k,
                l;
            // up left
            k = i - 1; l = j - 1;
            while (k >= START and l >= START) {
                W[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                --k; --l;
            }
            // up right
            k = i - 1; l = j + 1;
            while (k >= START and l < FINISH) {
                W[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                --k; ++l;
            }
            // down left
            k = i + 1; l = j - 1;
            while (k < FINISH and l >= START) {
                W[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                ++k; --l;
            }
            // down right
            k = i + 1; l = j + 1;
            while (k < FINISH and l < FINISH) {
                W[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                ++k; ++l;
            }
        } else if (F[i][j] == 'n') {
            W[i][j] = F[i][j];
            for (int k : {-2, 2}) for (int l : {-1, 1}) W[i + k][j + l] = F[i + k][j + l];
            for (int k : {-1, 1}) for (int l : {-2, 2}) W[i + k][j + l] = F[i + k][j + l];
        } else if (F[i][j] == 'b') {
            W[i][j] = F[i][j];

            int k,
                l;
            // up left
            k = i - 1; l = j - 1;
            while (k >= START and l >= START) {
                W[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                --k; --l;
            }
            // up right
            k = i - 1; l = j + 1;
            while (k >= START and l < FINISH) {
                W[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                --k; ++l;
            }
            // down left
            k = i + 1; l = j - 1;
            while (k < FINISH and l >= START) {
                W[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                ++k; --l;
            }
            // down right
            k = i + 1; l = j + 1;
            while (k < FINISH and l < FINISH) {
                W[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                ++k; ++l;
            }
        } else if (F[i][j] == 'p') {
            W[i][j] = F[i][j];
            W[i - 1][j - 1] = F[i - 1][j - 1];
            W[i - 1][j]     = F[i - 1][j];
            W[i - 1][j + 1] = F[i - 1][j + 1];
        }
    }

    // for black
    FORI FORJ {
        if (F[i][j] == 'K') {
            for (int k = i - 1; k <= i + 1; ++k)
                for (int l = j - 1; l <= j + 1; ++l)
                    B[k][l] = F[k][l];
        } else if (F[i][j] == 'R') {
            B[i][j] = F[i][j];
            // right
            for (int l = j + 1; l < FINISH; ++l) {
                B[i][l] = F[i][l];
                if (F[i][l] != '.')
                    break;
            }
            // left
            for (int l = j - 1; l >= START; --l) {
                B[i][l] = F[i][l];
                if (F[i][l] != '.')
                    break;
            }
            // up
            for (int k = i - 1; k >= START; --k) {
                B[k][j] = F[k][j];
                if (F[k][j] != '.')
                    break;
            }
            // down
            for (int k = i + 1; k < FINISH; ++k) {
                B[k][j] = F[k][j];
                if (F[k][j] != '.')
                    break;
            }
        } else if (F[i][j] == 'Q') { // actually, Q = R + B
            B[i][j] = F[i][j];

            // DA ROOOK PART
            // right
            for (int l = j + 1; l < FINISH; ++l) {
                B[i][l] = F[i][l];
                if (F[i][l] != '.')
                    break;
            }
            // left
            for (int l = j - 1; l >= START; --l) {
                B[i][l] = F[i][l];
                if (F[i][l] != '.')
                    break;
            }
            // up
            for (int k = i - 1; k >= START; --k) {
                B[k][j] = F[k][j];
                if (F[k][j] != '.')
                    break;
            }
            // down
            for (int k = i + 1; k < FINISH; ++k) {
                B[k][j] = F[k][j];
                if (F[k][j] != '.')
                    break;
            }

            // BISHOP PART
            int k,
                l;
            // up left
            k = i - 1; l = j - 1;
            while (k >= START and l >= START) {
                B[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                --k; --l;
            }
            // up right
            k = i - 1; l = j + 1;
            while (k >= START and l < FINISH) {
                B[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                --k; ++l;
            }
            // down left
            k = i + 1; l = j - 1;
            while (k < FINISH and l >= START) {
                B[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                ++k; --l;
            }
            // down right
            k = i + 1; l = j + 1;
            while (k < FINISH and l < FINISH) {
                B[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                ++k; ++l;
            }
        } else if (F[i][j] == 'N') {
            B[i][j] = F[i][j];
            for (int k : {-2, 2}) for (int l : {-1, 1}) B[i + k][j + l] = F[i + k][j + l];
            for (int k : {-1, 1}) for (int l : {-2, 2}) B[i + k][j + l] = F[i + k][j + l];
        } else if (F[i][j] == 'B') {
            B[i][j] = F[i][j];

            int k,
                l;
            // up left
            k = i - 1; l = j - 1;
            while (k >= START and l >= START) {
                B[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                --k; --l;
            }
            // up right
            k = i - 1; l = j + 1;
            while (k >= START and l < FINISH) {
                B[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                --k; ++l;
            }
            // down left
            k = i + 1; l = j - 1;
            while (k < FINISH and l >= START) {
                B[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                ++k; --l;
            }
            // down right
            k = i + 1; l = j + 1;
            while (k < FINISH and l < FINISH) {
                B[k][l] = F[k][l];
                if (F[k][l] != '.')
                    break;
                ++k; ++l;
            }
        } else if (F[i][j] == 'P') {
            B[i][j] = F[i][j];
            B[i + 1][j - 1] = F[i + 1][j - 1];
            B[i + 1][j]     = F[i + 1][j];
            B[i + 1][j + 1] = F[i + 1][j + 1];
        }
    }

    FORI {
        FORJ cout << W[i][j];
        cout << '\n';
    }
    cout << '\n';
    FORI {
        FORJ cout << B[i][j];
        cout << '\n';
    }

    return;
}
