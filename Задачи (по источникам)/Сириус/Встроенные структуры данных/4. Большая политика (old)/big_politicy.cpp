#include <iostream>
#include <set>
using namespace std;

long long N,
          tmp;
multiset<long long> towns;
long long answer;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        towns.insert(tmp);
    }

    long long a,
              b;
    while (towns.size() > 1) {
        a = *(towns.begin());
        towns.erase(towns.begin());
        b = *(towns.begin());
        towns.erase(towns.begin());

        answer += a + b;
        towns.insert(a + b);
    }
    
    cout << answer << '\n';
    return 0;
}
