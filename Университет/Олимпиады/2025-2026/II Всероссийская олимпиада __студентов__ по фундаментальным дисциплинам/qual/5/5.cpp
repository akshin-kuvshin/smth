// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool is_int(const std::string& S);

int main() {
	setlocale(LC_ALL, ""); // на моём ПК поддержка русского текста в консоли успешно (почти; см. ниже) включается, но, возможно, на другом ПК придётся написать "ru" вместо ""
	
	int N;
	std::cout << "(*) N = ";
	std::cin >> N;
	if (N < 1) {
		std::cerr << "[ОШИБКА]: кол-во городов, равное " << N << ", должно быть хотя бы 1." << std::endl;
		exit(1);
	}
	
	/* тут, к сожалению, опять, как и в задаче 3, так и не разобрался, как включить поддержку не только вывода русского
	*  текста, но и его ввода, поэтому ограничимся латинскими буквами, цифрами и спец. символами в качестве содержания
	*  для названий городов */
	std::vector<std::string> city_names(N);
	std::cout << "(*) Введите названия городов (предполагается, что название города не может\n    содержать пробелы внутри себя): ";
	for (auto& name : city_names)
		std::cin >> name;

	std::vector<std::vector<int>> dist(N, std::vector<int>(N));
	std::cout << "(*) Введите расстояния между городами в виде таблицы " << N << 'x' << N << ", где число, стоящее\n    в i-той строке и j-том столбце, обозначает расстояние в километрах от\n    города с номером i до города с номером j:" << std::endl;
	for (auto& row : dist)
		for (auto& d : row)
			std::cin >> d;

	std::string input;
	std::cout << "(*) Введите номер (нумерация с 1) или название исходного города: ";
	std::cin >> input;
	int base_city_index = (int)(std::find(city_names.begin(), city_names.end(), input) - city_names.begin());
	if (base_city_index == N) {
		if (not is_int(input)) {
			std::cerr << "[ОШИБКА]: некорректные входные данные для исходного города!" << std::endl;
			exit(2);
		}
		base_city_index = std::stoi(input);
		if (base_city_index < 1 or N < base_city_index) {
			std::cerr << "[ОШИБКА]: номер исходного города, равный " << base_city_index << ", должен быть от 1 до " << N << " включительно." << std::endl;
			exit(3);
		}
		--base_city_index;
	}

	std::vector<std::pair<int, int>> neighbours;
	for (int city_index = 0; city_index < N; ++city_index) {
		if (city_index == base_city_index)
			continue;
		neighbours.emplace_back(dist[base_city_index][city_index], city_index);
	}
	std::sort(neighbours.begin(), neighbours.end());

	std::cout << "(*) Города, отсортированные сначала по возрастанию расстояния от города " << city_names[base_city_index] << ",\n    а затем - по возрастанию названия (т.е. в лексикографическом порядке):" << std::endl;
	for (auto p : neighbours) { // начиная с определённого стандарта языка C++, я бы мог написать "for (auto [d, city_index] : neighbours)"
		int d = p.first,
		    city_index = p.second;
		std::cout << "- " << city_names[city_index] << ": " << d << " км" << std::endl;
	}
	return 0;
}

bool is_int(const std::string& S) {
	for (auto c : S)
		if (c < '0' or '9' < c)
			return false;
	return true;
}
