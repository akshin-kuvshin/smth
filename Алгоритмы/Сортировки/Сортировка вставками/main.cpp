#include <iostream>
using namespace std;

// Functions
void insertionSort(int*, int);

int main() {
    // Variables and input
    int size;
    cin >> size;
    
    int array[size];
    for (int i = 0; i < size; i++)
        cin >> array[i];
    
    // Algorithm
    insertionSort(array, size);
    
    // Output
    for (int i = 0; i < size; i++)
        cout << array[i] << ' ';
    cout << '\n';
    
    return 0;
}

void insertionSort(int *array, int size) {
    int j;
    for (int i = 1; i < size; i++) {
        j = i;
        while ( (array[j - 1] > array[j]) and (j != 0) ) {
            array[j - 1] ^= array[j];
            array[j] = array[j - 1] ^ array[j];
            array[j - 1] ^= array[j];
            
            j--;
        }
    }
}