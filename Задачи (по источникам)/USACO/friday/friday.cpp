/*
ID: daksion2
TASK: friday
LANG: C++
*/

#include <fstream>
using namespace std;

// Variables
int N,
    weekDays[7],
    day = 13,
    month = 0,
    year = 1900,
    dayOfWeek = 5,
    simpleYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    leapYear[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Functions
void input();
void solution();
void output();
bool isLeapYear(int);
bool isEndOfTimeLapse();

int main() {
    input();
    solution();
    output();
    
    return 0;
}

void input() {
    ifstream fin("friday.in");
    fin >> N;
    fin.close();
    return;
}

void solution() {
    do {
        weekDays[dayOfWeek]++;
        
        if (isLeapYear(year))
            dayOfWeek = (dayOfWeek + leapYear[month]) % 7;
        else
            dayOfWeek = (dayOfWeek + simpleYear[month]) % 7;
        
        month++;
        if (month == 12) {
            month = 0;
            year++;
        }
    } while (isEndOfTimeLapse());
    
    return;
}

void output() {
    ofstream fout("friday.out");
    fout << weekDays[5] << ' '
         << weekDays[6] << ' '
         << weekDays[0] << ' '
         << weekDays[1] << ' '
         << weekDays[2] << ' '
         << weekDays[3] << ' '
         << weekDays[4] << '\n';
    fout.close();
    return;
}

bool isLeapYear(int y) {
    return ( ( (y % 4 == 0) and (y % 100 != 0) ) or (y % 400 == 0) );
}

bool isEndOfTimeLapse() {
    return !(year >= 1900 + N);
}
