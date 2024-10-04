#include <iostream>
using namespace std;
typedef long long int lli;

lli Q;
lli l,
    r;
lli current_num,
    current_luck,
    best_num,
    best_luck;

lli luckiness(lli);

int main() {
    cin >> Q;
    while (Q--) {
        cin >> l >> r;
        current_num = best_num = l;
        current_luck = best_luck = luckiness(l);

        while ((current_num <= r) and (best_luck != 9LL)) {
            current_luck = luckiness(current_num);
            if (best_luck < current_luck) {
                best_num = current_num;
                best_luck = current_luck;
            }

            ++current_num;
        }

        cout << best_num << '\n';
    }    
    return 0;
}

lli luckiness(lli num) {
    lli min_digit,
        max_digit;    
    min_digit = max_digit = num % 10LL;

    while (num) {
        min_digit = min(min_digit, num % 10LL);
        max_digit = max(max_digit, num % 10LL);
        num /= 10LL;
    }

    return max_digit - min_digit;
}
