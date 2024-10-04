#include <iostream>
#include <vector>
using namespace std;

// Variables
int sz, // Количество шаров (изменяется, т.к. цепочки шаров могут удаляться)
    tmpBall, // Временная переменная для ввода массива шаров
	destroyedBallsAmount, // Кол-во уничтоженных шаров
	l, // Левая граница удаляемой цепочки
	r, // Правая граница удаляемой цепочки
	ballColor; // Цвет шаров в цепочке, которую я рассматриваю
vector<int> balls; // Массив шаров
bool isNeedToCheck; // Переменная, отвечающая за то, нужно ли проверять массив на наличие цепочек

// Functions
void ballsInput(); // Ввод массива шаров
void ballsDelete(); // Удаление части массива шаров в промежутке индексов [l; r]
void findingDestroyedBallsAmount(); // Поиск кол-ва уничтоженных шаров

int main() {
	// Input
	cin >> sz;
	ballsInput();
	
	// Algorithm
	findingDestroyedBallsAmount();
	
	// Output
	cout << destroyedBallsAmount << '\n';
	
	return 0;
}

void ballsInput() {
	for (int i = 0; i < sz; i++) {
		cin >> tmpBall;
		balls.push_back(tmpBall);
	}
}

void ballsDelete() {
	for (int i = r; i >= l; i--)
		balls.erase(balls.begin() + i);
}

void findingDestroyedBallsAmount() {
	do {
		if (balls.size() == 0)
			break;
		
		sz = balls.size();
		l = 0;
		r = -1;
		ballColor = balls.at(0);
		isNeedToCheck = false;
		
		for (int i = 0; i < sz; i++) {
			if (balls.at(i) == ballColor)
				r++;
			else {
				if (r - l + 1 >= 3) {
					ballsDelete();
					destroyedBallsAmount += r - l + 1;
					isNeedToCheck = true;
					break;
				} else {
					ballColor = balls.at(i);
					l = r = i;
				}
			}
		}
		
		if (r - l + 1 >= 3 && !isNeedToCheck) {
			ballsDelete();
			destroyedBallsAmount += r - l + 1;
			isNeedToCheck = true;
		}
	} while (isNeedToCheck);
}
