#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = (int)1e3 + 5;

pair<int, int> max_decreasing_sequence(int*, int);

int main() {
    int N,
        A[MAX_SIZE];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    int h = (int)(min_element(A, A + N) - A);
    pair<int, int> ans = max_decreasing_sequence(A, h);
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}

pair<int, int> max_decreasing_sequence(int *A, int N) {
    int max_len = 0,
        j = -1,
        cur_len = 1;
    for (int i = 1; i < N; ++i)
        if (A[i - 1] > A[i])
            ++cur_len;
        else {
            if (cur_len > max_len) {
                max_len = cur_len;
                j = i - cur_len;
            }
            cur_len = 1;
        }
    max_len = max(max_len, cur_len);
    return make_pair(j, j + max_len - 1);
}
