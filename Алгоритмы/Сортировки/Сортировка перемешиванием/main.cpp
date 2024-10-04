#include <iostream>
using namespace std;

// Functions
void coctailSort(int*, int);

int main() {
    // Variables and input
    int size;
    cin >> size;
    
    int array[size];
    for (int i = 0; i < size; i++)
        cin >> array[i];
    
    // Algorithm
    coctailSort(array, size);
    
    // Output
    for (int i = 0; i < size; i++)
        cout << array[i] << ' ';
    cout << '\n';
    
    return 0;
}

void coctailSort(int *A, int sz) {
    int left = 0,
        right = sz - 1,
        border = 0;
    
    do {
        for (int i = left; i < right; i++)
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                border = i;
            }
        right = border;
        
        for (int i = right; i > left; i--)
            if (A[i - 1] > A[i]) {
                swap(A[i - 1], A[i]);
                border = i;
            }
        left = border;
    } while (left != right);
}