// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>

const int INF = (int)1e9 + 1;

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n),
	                 div5,
	                 even,
	                 odd;
	for (auto& ai : a) {
		std::cin >> ai;
		if (ai % 5 == 0)
			div5.push_back(ai);
		(ai % 2 == 0 ? even : odd).push_back(ai);
	}
	if (div5.empty()) {
		std::cout << 0 << std::endl;
		return 0;
	}

	int max_sum = -INF;
	for (auto d : div5) {
		auto& v = d % 2 == 0 ? even : odd;
		for (auto x : v) {
			if (d == x)
				continue;
			max_sum = std::max(max_sum, d + x);
		}
	}
	
	std::cout << max_sum << std::endl;
	return 0;
}
