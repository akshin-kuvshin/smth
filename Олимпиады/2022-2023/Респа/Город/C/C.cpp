#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli N_max = 18LL,
          DIGITS_MAX = 8LL;

lli N,
    A[N_max + 5LL];
lli current,
    ind;
vector<lli> _indexes;
lli answer;

bool check(const vector<lli>&);

int main() {
    cin >> N;
    for (int i = 0; i < (int)N; ++i)
        cin >> A[i];
    
    for (lli boolean = (1LL << N) - 1LL; boolean > 0LL; --boolean) {
        current = boolean;
        ind = 0LL;
        _indexes.clear();

        while (current) {
            if (current & 1LL)
                _indexes.push_back(ind);
            current >>= 1LL;
            ++ind;
        }

        if (check(_indexes))
            answer = max(answer, (lli)_indexes.size());
    }

    cout << answer << '\n';
    return 0;
}

bool check(const vector<lli> &indexes) {
    lli sums[DIGITS_MAX + 5LL] = {0LL};
    for (int i = 0; i < (int)indexes.size(); ++i) {
        lli elem = A[indexes[i]],
            digit_ind = 0LL;

        while (elem) {
            sums[digit_ind++] += (elem % 10LL);
            elem /= 10LL;
        }
    }

    for (int i = 0; i < (int)DIGITS_MAX; ++i)
        if (sums[i] >= 10)
            return false;
    return true;
}
