// author: Danila "akshin_" Axyonov

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

std::vector<int> get_primes(int N_max);

int main() {
	int N;
	std::cin >> N;

	auto primes = get_primes(N);
	std::vector<std::tuple<int, int, int>> triples;
	for (int i = 0; i < (int)primes.size(); ++i) {
		int p = primes[i];
		for (int j = i; j < (int)primes.size(); ++j) {
			int q = primes[j];

			int r = N - p - q;
			if (r < q)
				break;
			if (not std::binary_search(primes.begin(), primes.end(), r))
				continue;

			triples.emplace_back(p, q, r);
		}
	}

	std::cout << triples.size() << std::endl;
	for (auto t : triples)
		std::cout << std::get<0>(t) << ' ' << std::get<1>(t) << ' ' << std::get<2>(t) << std::endl;

	return 0;
}

std::vector<int> get_primes(int N_max) {
	std::vector<bool> is_prime(N_max + 1, true);
	for (int i = 2; i * i <= N_max; ++i)
		for (int j = i * i; j <= N_max; j += i)
			is_prime[j] = false;

	std::vector<int> primes;
	for (int i = 2; i <= N_max; ++i)
		if (is_prime[i])
			primes.push_back(i);
	return primes;
}
