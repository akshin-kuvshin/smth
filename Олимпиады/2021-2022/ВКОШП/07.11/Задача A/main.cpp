#include <iostream>
using namespace std;

// Constants
const int n_max = 1e5; // checked

// Variables
long long n, // checked
    	  skills[n_max + 5], // checked
    	  answer,
    	  numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    	  swapped_numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    	  valuables[10], // checked
    	  pows_of_10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000}, // checked
		  indexes_of_sorted_numbers[10];
bool is_non_zero[10]; // checked

// Functions
void input();
void solution();
void output();
int get_first_digit(int);
void get_non_zero_digits();
void get_digits_valuables();
void sort_valuables();
void get_indexes_of_sorted_numbers();
void except_non_zero_digits();
void get_answer();

int main() {
    input();
    solution();
    output();
    
    return 0;
}

void input() {
	// Написать ios_base... и cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> skills[i];
    return;
}

void solution() {
	get_non_zero_digits();
    get_digits_valuables();
    sort_valuables();
    get_indexes_of_sorted_numbers();
    except_non_zero_digits();
    get_answer();
    
    return;
}

void output() {
    cout << answer << '\n';
    return;
}

int get_first_digit(int number) {
	while (number != number % 10)
		number /= 10;
	return number;
}

void get_non_zero_digits() {
	for (int i = 0; i < n; i++)
		is_non_zero[get_first_digit(skills[i])] = true;
	return;
}

void get_digits_valuables() {
    long long number;
    for (int i = 0; i < n; i++) {
    	number = skills[i];
        for (int j = 0; number; j++) {
            valuables[number % 10] += pows_of_10[j];
            number /= 10;
        }
    }
    return;
}

void sort_valuables() {
	// Заменить сортировку на сортировку по индексу
	int j;
	for (int i = 1; i < 10; i++) {
		j = i;
		while ( (valuables[j - 1] > valuables[j]) and j) {
			swap(numbers[j - 1], numbers[j]);
			swap(valuables[j - 1], valuables[j]);
			
			j--;
		}
	}
	return;
}

void get_indexes_of_sorted_numbers() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (i == numbers[j]) {
				indexes_of_sorted_numbers[i] = j;
				break;
			}
	return;
}

void except_non_zero_digits() {
	if (!is_non_zero[numbers[0]])
		return;
	
	int iofdtcbz = -1;
	for (int i = 1; i < 10; i++)
		if (!is_non_zero[numbers[i]]) {
			iofdtcbz = i;
			break;
		}
	
	int tmp = numbers[iofdtcbz];
	for (int i = iofdtcbz; i > 0; i--)
		numbers[i] = numbers[i - 1];
	numbers[0] = tmp;
	
	get_indexes_of_sorted_numbers();
	return;
}

void get_answer() {
	long long number;
    for (int i = 0; i < n; i++) {
    	number = skills[i];
        for (int j = 0; number; j++) {
            answer += swapped_numbers[indexes_of_sorted_numbers[number % 10]] * pows_of_10[j];
            number /= 10;
        }
    }
    return;
}
