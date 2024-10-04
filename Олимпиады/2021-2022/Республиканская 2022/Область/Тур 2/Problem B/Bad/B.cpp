// DONE
#include <iostream>
#include <vector>
using namespace std;

// Constants
const int N_max = 2e5,
		  M_max = 2e5;

// Variables
int N,
	M,
	a,
	b,
	size[N_max + 5],
	c[N_max + 5],
	general_c,
	answer = 1,
	collection[2][N_max + 5],
	_begin[2],
	_end[2];
vector<int> graph[N_max + 5];
bool flag,
	 is_need_to_check,
	 used[N_max + 5];

// Functions
void input();
void solution();
void output();
void check_current_collection(bool, int, int, int&);
void add_friends(bool, int, int&);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N >> M;
	
	// —оздаю список смежностей
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		++size[a];
		++size[b];
	}
	
	for (int i = 1; i <= N; ++i)
		cin >> c[i];
	
	return;
}

void solution() {
	general_c = c[1];
	used[1] = true;
	
	add_friends(flag, 1, _end[flag]);
	
	do {
		_begin[!flag] = _end[!flag] = 0;
		is_need_to_check = false;
		
		check_current_collection(flag, _begin[flag], _end[flag], _end[!flag]);
		
		flag = !flag;
	} while (is_need_to_check);
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

// ѕеребирает текущий список ожидающих обработки вершин.
// ѕараметры: номер списка (коллекции), индекс начала, индекс конца,
// индекс конца необрабатываемого списка по ссылке (чтобы мы могли мен€ть его пр€мо из функции).
void check_current_collection(bool _fl, int _b, int _e, int &non_current_end) {
	for (int i = _b; i < _e; ++i)
		if (c[collection[_fl][i]] <= general_c) {
			++answer;
			general_c += c[collection[_fl][i]];
			is_need_to_check = true;
			add_friends(!_fl, collection[_fl][i], _end[!_fl]);
		} else collection[!_fl][non_current_end++] = collection[_fl][i];
	return;
}

// ƒобавить в очередь новых знакомых.
// ѕараметры: номер списка, куда нужно добавл€ть новых знакомых, друг-предок,
// индекс конца необрабатываемого списка по ссылке (чтобы мы могли мен€ть его пр€мо из функции).
void add_friends(bool _fl, int primal, int &non_current_end) {
	int _sz = size[primal];
	for (int _this = 0; _this < _sz; ++_this)
		if (!used[graph[primal][_this]]) {
			collection[_fl][non_current_end++] = graph[primal][_this];
			used[graph[primal][_this]] = true;
		}
	return;
}
