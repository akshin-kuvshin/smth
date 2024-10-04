// Очень бредовое решение по принципу DFS (страшно!)
/* Сначала мы очень хитрым образом запоминаем месторасположение всех элементов. Делаем это так, чтобы, имея значение элемента,
 * мы могли получить все индексы, где этот элемент расположен. Далее работаем по принципу DFS-а: перебираем просто все варианты
 * того, как мы можем выбрать контрольные точки. Примечание: контрольная точка - единственный элемент i-того отрезка массива A,
 * который будет равен i-тому элементу массива B. Найдя один вариант выбора контрольный точек, мы просто просчитываем количество
 * вариантов разбить массив именно с этими точками и прибавляем к общему ответу. Конечно, всё время работаем с модульной арифметикой
 * и каждый раз при вычислении ответа (даже косвенного, частичного) берём по модулю d.
 * 
 * (a * b) % d == (a % d * b % d) % d
 * (a + b) % d == (a % d + b % d) % d
 */

// TODO
#include <iostream>
#include <vector>
#define LAST -1
using namespace std;

// Constants
const int MAX_SIZE = 5e5,
		  d = 998244353; // Дано в условии, ответ берём по модулю d

// Variables (общие)
int N,
	M,
	A[MAX_SIZE + 5],
	B[MAX_SIZE + 5];
long long answer;
// Переменные, запоминающие индексы всех элементов
int order[MAX_SIZE + 5],
	id;
bool used[MAX_SIZE + 5];
vector<vector<int>> indexes;
// Переменные для DFS-а
int stack[MAX_SIZE + 5];

// Functions
void input();
void solution();
void output();
void get_indexes();
long long DFS(int);
long long _count(const int*, int);
vector<int>& ind_arr(int);
int _sz(int);
int ind(int, int);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int j = 0; j < M; ++j)
		cin >> B[j];
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

void solution() {
	get_indexes();
	answer = DFS(0);
	
	return;
}

// Массив used показывает, был ли уже найден подобный элемент ранее.
// Массив order показывает, под каким номером в массиве indexes хранятся индексы элементов
// с конкретным значением.
// Переменная id указывает, сколько уникальных элементов уже найдено,
// т.е. какой номер получит следующий уникальный элемент.
// Массив indexes хранит индексы всех элементов.
void get_indexes() {
	for (int i = 0; i < N; ++i)
		if (used[A[i]]) { // Элемент найден ранее, уникальным уже не является.
			ind_arr(A[i]).push_back(i);
		} else { // Найден новый элемент
			used[A[i]] = true;
			order[A[i]] = id++;
			indexes.push_back(vector<int>(1, i));
		}
	return;
}

// Перебирает все варианты выбора контрольных точек.
// Переменная k означает, что мы выбираем контрольную точку под номером k, т.е. для k-того отрезка,
// т.е. под k-тый элемент массива B.
int DFS(int k) {
	// Крайний случай рекурсии
	// Нашли одну из выборок контрольных точек, считаем варианты вручную, возвращаем число, заново DFS уже не вызываем.
	if (k == M) {
		int returning_value = _count(stack, k);
		return returning_value;
	}
	
	int current = B[k];
	long long ans = -1, // т.е. не определён
			  tmp;
	
	// Если мы выбираем первую контрольную точку, то мы просто обязаны брать ближайщую к началу массива A,
	// потому что элементы от начала массива до первой контрольной точки нельзя отсечь, отделить =>
	// если мы будем первой контрольной точкой брать не ближайшую к началу, то у нас нарушится правило деления
	// на отрезки. Также будем поступать и с последней контрольной точкой, только нам придётся брать
	// её последнее вхождения в массив A.
	if (!k) {
		int to = ind(current, 0);
		stack[0] = to;
		ans = DFS(k + 1);
	} else if (k == M - 1) {
		int to = ind(current, LAST);
		stack[M - 1] = to;
		ans = DFS(k + 1);
	} else
		for (int to : ind_arr(current)) {
			if (stack[k - 1] > to)
					continue; // потому что i-тая контрольная точка просто обязана распологаться раньше (i + 1)-ой.
			
			stack[k] = to;
			tmp = DFS(k + 1);
			
			if (ans == -1) // первое определение
				ans = tmp;
			else
				ans = (ans % d + tmp % d) % d;
		}
	
	return (ans == -1) ? 0 : ans; // если до сих пор не определён, то с имеющейся изначально конфигурацией контрольных точек
								  // попросту невозможно поделить массив A так, как требуется.
}

// Функция подсчёта вариантов деления при определённой конфигурации контрольных точек.
// control_dots - индексы контрольных точек в массиве A
long long _count(const int *control_dots, int _size) {
	// Псевдо-указатели (индексы)
	int _begin,
		_end,
		_new_begin,
		_new_end;
	
	// НЕиндексы
	int num_b, // контрольная точка 1
		num_e; // контрольная точка 2
	long long _ans = 1, // изначальное значение произведения нуля чисел
			  _tmp;
	
	for (int i = 0; i + 1 < _size; ++i) {
		_new_begin = -1; // не определено
		_new_end = -1; // не определено
		
		_begin = control_dots[i];
		_end = control_dots[i + 1];
		num_b = A[_begin];
		num_e = A[_end];
		
		for (int k = _begin + 1; k < _end; ++k)
			if (A[k] == num_b) {
				_new_end = k;
				break;
			}
		for (int m = _end - 1; m > _begin; --m)
			if (A[m] == num_e) {
				_new_begin = m;
				break;
			}
		
		// Если кто-то не определён, то границу менять не надо, ставим
		// значения в исходное положение.
		_new_begin = (_new_begin == -1) ? _begin : _new_begin;
		_new_end = (_new_end == -1) ? _end : _new_end;
		
		// При между выбранными двумя контрольными точками никак нельзя поставить границу.
		if (_new_begin >= _new_end)
			return 0;
		
		_tmp = _new_end - _new_begin;
		_ans = ( (_ans % d) * (_tmp % d) ) % d;
	}
	
	return _ans;
}

vector<int>& ind_arr(int elem) {
	return indexes[order[elem]];
}

int _sz(int elem) {
	return ind_arr(elem).size();
}

int ind(int elem, int i) {
	if (i == LAST)
		return ind_arr(elem)[_sz(elem) - 1];
	return ind_arr(elem)[i];
}
