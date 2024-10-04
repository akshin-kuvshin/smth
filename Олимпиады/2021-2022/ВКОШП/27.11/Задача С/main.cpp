#include <iostream>
#include <string>
#define EXIT_CODE true
using namespace std;

// Variables
int n,
	x,
	y,
	Lx,
	Rx,
	Ly,
	Ry;
string S;

// Variables
void input();
void solution();
void solo_binary_search();
void double_binary_search();
void set_start_valuables();
void attempt();
int get_new_x();
int get_new_y();
bool change_search_area();

int main() {
	input();
	solution();
	
	return 0;
}

void input() {
	cin >> n;
	return;
}

void solution() {
	set_start_valuables();
	attempt();
	
	if (S == "OK")
		return;
	
	if (S.size() == 1)
		solo_binary_search();
	else // S.size() == 2
		double_binary_search();
	
	return;
}

void solo_binary_search() {
	if ( (S == "N") or (S == "S") ) {
		while (true) {
			y = get_new_y();
			
			attempt();
			
			if (change_search_area())
				break;
		}
	} else { // S == "W" or S == "E"
		while (true) {
			x = get_new_x();
			
			attempt();
			
			if (change_search_area())
				break;
		}
	}
	
	return;
}

void double_binary_search() {
	while (true) {
		x = get_new_x();
		y = get_new_y();
		
		attempt();
		
		if (change_search_area())
			break;
		
		if (S.size() == 1)
			solo_binary_search();
	}
	
	return;
}

void set_start_valuables() {
	x = y = 0; // начинаем с верхнего левого угла с координатами (0; 0)
	Lx = Ly = 0; // потому что изначальная область поиска - вся плокость
	Rx = Ry = n - 1; // та же причина
	
	return;
}

void attempt() {
	cout << y + 1 << ' ' << x + 1 << '\n';
	cout.flush();
	
	cin >> S;
	
	return;
}

int get_new_x() {
	return (Lx + Rx) / 2;
}

int get_new_y() {
	return (Ly + Ry) / 2;
}

bool change_search_area() {
	if (S == "OK")
		return EXIT_CODE;
	
	if (S.find('N') != -1)
		Ry = y - 1;
	else if (S.find('S') != -1)
		Ly = y + 1;
	if (S.find('W') != -1)
		Rx = x - 1;
	else if (S.find('E') != -1)
		Lx = x + 1;
	return false;
}
