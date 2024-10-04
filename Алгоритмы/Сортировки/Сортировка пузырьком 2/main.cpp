#include <iostream>
using namespace std;

// Functions
void bubbleSort(int*, int);

int main() {
    // Variables and input
    int size;
    cin >> size;
    
    int array[size];
    for (int i = 0; i < size; i++)
        cin >> array[i];
    
    // Algorithm
    bubbleSort(array, size);
    
    // Output
    for (int i = 0; i < size; i++)
        cout << array[i] << ' ';
    cout << '\n';
    
    return 0;
}

void bubbleSort(int *array, int size) {
    bool isNeedToCheck;
    do {
        isNeedToCheck = false;
        for (int i = 1; i < size; i++)
            if (array[i - 1] > array[i]) {
                isNeedToCheck = true;
                
                array[i - 1] ^= array[i];
                array[i] = array[i - 1] ^ array[i];
                array[i - 1] ^= array[i];
            }
    } while (isNeedToCheck);
}