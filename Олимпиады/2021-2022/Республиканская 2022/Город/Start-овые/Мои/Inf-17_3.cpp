#include <iostream>
#include <vector>
using namespace std;

// Constants
const int N_max = 1e5;

// Variables
int N,
    A[N_max + 5],
    maxs_from_begin[N_max + 5],
    _ans,
    new_edges[N_max + 5],
    top;
vector<int> subarrays_edges;

// Functions
void get_start_edges() {
    int tmp = -1;
    for (int i = 0; i < N; ++i)
        if (maxs_from_begin[i] != tmp) {
            tmp = maxs_from_begin[i];
            subarrays_edges.push_back(i);
        }
    subarrays_edges.push_back(N);
    
    return;
}

bool is_no_higher_before(int begin, int index) {
    for (int k = index - 1; k >= begin; --k)
        if (A[k] > A[index])
            return false;
    return true;
}

bool is_no_lower_after(int end, int index) {
    for (int k = index + 1; k < end; ++k)
        if (A[index] > A[k])
            return false;
    return true;
}

void check_subarray_for_subarrays(int begin, int end) {
    new_edges[top++] = begin;
    for (int i = begin + 1; i < end; ++i)
        if (is_no_higher_before(begin, i) and is_no_lower_after(end, i)) {
            new_edges[top++] = i;
        	begin = i;
        }
    return;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        
        if (i == 0) maxs_from_begin[0] = A[0];
        else maxs_from_begin[i] = max(maxs_from_begin[i - 1], A[i]);
    }
    return;
}

void solution() {
    get_start_edges();
    
    int _sz = subarrays_edges.size();
    for (int i = 0; i < _sz - 1; ++i)
        check_subarray_for_subarrays(subarrays_edges[i], subarrays_edges[i + 1]);
    
    _ans = top;
    return;
}

void output() {
    cout << _ans << '\n';
    return;
}

int main() {
    input();
    solution();
    output();
    return 0;
}