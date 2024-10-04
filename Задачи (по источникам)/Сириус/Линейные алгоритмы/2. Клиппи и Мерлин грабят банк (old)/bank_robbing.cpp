#include <iostream>
using namespace std;

const int N_max = 1e5;

int N,
    K,
    A[N_max + 5],
    maxs[N_max + 5],
    maxs_ind[N_max + 5],
    robbing_sum[N_max + 5];
pair<int, int> ans_ind;

int main() {
    /* input */
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    /* solution */
    maxs[0] = A[0];
    maxs_ind[0] = 0;
    robbing_sum[0] = -1;
    for (int i = 1; i < N; ++i) {
        if (maxs[i - 1] < A[i]) {
            maxs[i] = A[i];
            maxs_ind[i] = i;
        } else {
            maxs[i] = maxs[i - 1];
            maxs_ind[i] = maxs_ind[i - 1];
        }

        if (i == K + 1) {
            robbing_sum[i] = A[0] + A[i];
            ans_ind = make_pair(0, i);
        } else
            if (A[i] + maxs[i - K - 1] > robbing_sum[i - 1]) {
                robbing_sum[i] = A[i] + maxs[i - K - 1];
                ans_ind = make_pair(maxs_ind[i - K - 1], i);
            } else
                robbing_sum[i] = robbing_sum[i - 1];
    }

    /* output */
    cout << ans_ind.first + 1 << ' ' << ans_ind.second + 1 << '\n';

    return 0;
}
