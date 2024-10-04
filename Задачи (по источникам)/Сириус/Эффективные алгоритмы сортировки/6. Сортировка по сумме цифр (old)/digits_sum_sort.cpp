#include <iostream>
#include <algorithm>
using namespace std;

const int N_max = 1e3;

int N,
    tmp;
pair<int, int> A[N_max + 5];

bool comp(pair<int, int>, pair<int, int>);
int digits_sum(int);

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        A[i] = make_pair(tmp, i);
    }
    
    sort(A, A + N, comp);

    for (int i = 0; i < N; ++i)
        cout << A[i].first << ' ';
    cout << '\n';
    return 0;
}

bool comp(pair<int, int> num1, pair<int, int> num2) {
    int digits_sum_1 = digits_sum(num1.first),
        digits_sum_2 = digits_sum(num2.first);
    
    if (digits_sum_1 == digits_sum_2)
        return (num1.second < num2.second);
    return (digits_sum_1 > digits_sum_2);
}

int digits_sum(int number) {
    int sum = 0;
    while (number) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
