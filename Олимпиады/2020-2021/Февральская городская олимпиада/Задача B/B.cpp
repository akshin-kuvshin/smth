#include <iostream>

int main() {
	int K;
	long long answer;
	
	std::cin >> K;
	answer = 10 * (K - 1) + 5;
	answer *= answer;
	std::cout << answer << '\n';
	
	system("pause");
	return 0;
}