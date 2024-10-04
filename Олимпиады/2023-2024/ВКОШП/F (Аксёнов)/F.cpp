#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e3 + 5LL,
          INF = (lli)1e18 + 1LL;

lli N,
    A[MAX_SIZE][MAX_SIZE];
lli row_sum[MAX_SIZE],
    col_sum[MAX_SIZE];
unordered_map<lli, lli> rowm,
                        colm;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        for (int j = 0; j < (int)N; ++j) {
            cin >> A[i][j];
            row_sum[i] += A[i][j];
            col_sum[j] += A[i][j];
        }

    for (int i = 0; i < (int)N; ++i) {
        ++rowm[row_sum[i]];
        ++colm[col_sum[i]];
    }

    if ((lli)rowm.size() == 3LL and (lli)colm.size() == 3LL) {
        lli max_row = -1LL,
            min_row = INF;
        for (pair<lli, lli> p : rowm) {
            max_row = max(max_row, p.first);
            min_row = min(min_row, p.first);
        }

        lli max_row_ind,
            min_row_ind;
        for (int i = 0; i < (int)N; ++i) {
            if (row_sum[i] == max_row)
                max_row_ind = (lli)i;
            if (row_sum[i] == min_row)
                min_row_ind = (lli)i;
        }

        lli max_col_ind,
            min_col_ind;
        for (int i = 0; i < (int)N; ++i) {
            if (col_sum[i] == max_row)
                max_col_ind = (lli)i;
            if (col_sum[i] == min_row)
                min_col_ind = (lli)i;
        }

        ++max_row_ind;
        ++min_row_ind;
        ++max_col_ind;
        ++min_col_ind;

        cout << max_row_ind << ' ' << max_col_ind << '\n' << min_row_ind << ' ' << min_col_ind << '\n';
    } else if ((lli)rowm.size() == 3LL and (lli)colm.size() == 1LL) {
        lli max_row = -1LL,
            min_row = INF;
        for (pair<lli, lli> p : rowm) {
            max_row = max(max_row, p.first);
            min_row = min(min_row, p.first);
        }

        lli max_row_ind,
            min_row_ind;
        for (int i = 0; i < (int)N; ++i) {
            if (row_sum[i] == max_row)
                max_row_ind = (lli)i;
            if (row_sum[i] == min_row)
                min_row_ind = (lli)i;
        }

        lli d = (max_row - min_row) >> 1;

        lli col;
        for (int i = 0; i < (int)N; ++i)
            if (A[max_row_ind][i] - A[min_row_ind][i] == d) {
                col = (lli)i;
                break;
            }

        ++max_row_ind;
        ++min_row_ind;
        ++col;

        cout << max_row_ind << ' ' << col << '\n' << min_row_ind << ' ' << col << '\n';
    } else if ((lli)rowm.size() == 1LL and (lli)colm.size() == 3LL) {
        lli max_col = -1LL,
            min_col = INF;
        for (pair<lli, lli> p : colm) {
            max_col = max(max_col, p.first);
            min_col = min(min_col, p.first);
        }

        lli max_col_ind,
            min_col_ind;
        for (int i = 0; i < (int)N; ++i) {
            if (col_sum[i] == max_col)
                max_col_ind = (lli)i;
            if (col_sum[i] == min_col)
                min_col_ind = (lli)i;
        }

        lli d = (max_col - min_col) >> 1;

        lli row;
        for (int i = 0; i < (int)N; ++i)
            if (A[i][max_col_ind] - A[i][min_col_ind] == d) {
                row = (lli)i;
                break;
            }

        ++max_col_ind;
        ++min_col_ind;
        ++row;

        cout << row << ' ' << max_col_ind << '\n' << row << ' ' << min_col_ind << '\n';
    }

    return 0;
}
