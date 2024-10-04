//#include <iostream> // закомментировать для файлового ввода
#include <fstream> // раскомментировать для файлового ввода
#include <queue>
//#define fin cin // закомментировать для файлового ввода
//#define fout cout // закомментировать для файлового ввода
using namespace std;

// Structures
struct Location {
	int x;
	int y;
	int money;
};

// Constants
const int MAX_SIZE = 1e4;

// Variables
int M,
	N,
	Q,
	A[MAX_SIZE + 5][MAX_SIZE + 5],
	B[MAX_SIZE + 5][MAX_SIZE + 5],
	T[MAX_SIZE + 5][MAX_SIZE + 5],
	answer = -1;
// Переменные для BFS-а
queue<Location> q;

// Functions
void input();
void solution();
void output();
void BFS();

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	ifstream fin("a.in"); // раскомментировать для файлового ввода
	
	fin >> M >> N >> Q;
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			fin >> A[i][j] >> B[i][j] >> T[i][j];
	
	fin.close(); // раскомментировать для файлового ввода
	return;
}

void solution() {
	BFS();
	return;
}

void output() {
	ofstream fout("a.out"); // раскомментировать для файлового ввода
	fout << answer << '\n';
	fout.close(); // раскомментировать для файлового ввода
	return;
}

void BFS() {
	// Вручную обрабатываем первую "вершину" (клетку)
	Location start;
	start.x = 1;
	start.y = 1;
	start.money = Q;
	q.push(start);
	
	Location current,
			 to;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		
		// Крайний случай, мы пришли
		if ( (current.x == M) and (current.y == N) ) {
			answer = max(answer, current.money);
			continue;
		}
		
		// Плохой случай, мы вышли за границы
		if ( (current.x > M) or (current.y > N) )
			continue;
		
		// Перебираем все 5 вариантов шага.
		// Примечание: мы не учитываем вариант выхода за границу, т.к. он учтён в "плохом случае".
		// Когда мы обращаемся к стоимости клеточки за границей, то она равна нуля,
		// т.к. определена в глобальной области и не изменялась.
		
		if (current.money >= A[current.x][current.y]) {
			to = current;
			to.x += 1;
			to.money -= A[current.x][current.y];
			to.money += T[to.x][to.y];
			q.push(to);
			
			to = current;
			to.y += 1;
			to.money -= A[current.x][current.y];
			to.money += T[to.x][to.y];
			q.push(to);
			
			to = current;
			to.x += 1;
			to.y += 1;
			to.money -= A[current.x][current.y];
			to.money += T[to.x][to.y];
			q.push(to);
		} if (current.money >= B[current.x][current.y]) {
			to = current;
			to.x += 2;
			to.money -= A[current.x][current.y];
			to.money += T[to.x][to.y];
			q.push(to);
			
			to = current;
			to.x += 1;
			to.money -= A[current.x][current.y];
			to.money += T[to.x][to.y];
			q.push(to);
		}
	}
	
	return;
}
