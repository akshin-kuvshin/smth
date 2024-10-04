#include <iostream>
using namespace std;

// Variables
char S[8];
int days,
	monthes,
	years,
	totalDays,
	startMonth,
	february;

// Functions
void input();
void solution();
void output();

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> S;
	
	days = (S[0] - '0') * 10 + (S[1] - '0');
	monthes = (S[2] - '0') * 10 + (S[3] - '0');
	years = (S[4] - '0') * 1000 + (S[5] - '0') * 100 + (S[6] - '0') * 10 + (S[7] - '0');
}

void solution() {
	// —чЄт общего кол-ва дней по нынешнему числу
	totalDays += days;
	
	// ќпределение с какого мес€ца начинать считать,
	// т.к. €нварь первого года в учЄт не идЄт
	if (years == 1) startMonth = 2;
	else startMonth = 1;
	
	// ќпределение количества дней в феврале нынешнего года
	if ( ( (years % 4 != 0) or (years % 100 == 0) ) and (years % 400 != 0) ) february = 28;
	else february = 29;
	
	// —чЄт общего количества дней по мес€цам нынешнего года
	for (int i = startMonth; i < monthes; i++)
		switch (i) {
			case 1:
				totalDays += 31;
				break;
			case 2:
				totalDays += february;
				break;
			case 3:
				totalDays += 31;
				break;
			case 4:
				totalDays += 30;
				break;
			case 5:
				totalDays += 31;
				break;
			case 6:
				totalDays += 30;
				break;
			case 7:
				totalDays += 31;
				break;
			case 8:
				totalDays += 31;
				break;
			case 9:
				totalDays += 30;
				break;
			case 10:
				totalDays += 31;
				break;
			case 11:
				totalDays += 30;
				break;
			case 12:
				totalDays += 31;
				break;
		}
	
	// —чЄт общего количества дней по годам (от 1 до years - 1,
	// т.к. нынешний год ещЄ не закончилс€, а его мес€ца и дни
	// ћы уже посчитали ранее)
	for (int i = 1; i < years; i++)
		if ( ( (i % 4 != 0) or (i % 100 == 0) ) and (i % 400 != 0) )
			totalDays += 365;
		else
			totalDays += 366;
}

void output() {
	cout << totalDays << '\n';
}
