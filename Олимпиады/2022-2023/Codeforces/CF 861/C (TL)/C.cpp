#include <iostream>
using namespace std;
typedef long long int lli;

lli Q;
lli l,
    r;
lli l_len;
lli answer;

void solve();
lli len(lli);
bool check_0(lli);
lli luckiness(lli);

int main() {
    cin >> Q;
    while (Q--) {
        solve();
        cout << answer << '\n';
    }
    return 0;
}

void solve() {
    cin >> l >> r;

    // Перебираем удачливость 0 (кол-во цифр или равно кол-ву цифр в l, или на единицу больше).
    l_len = len(l);

    if (check_0(l_len)) return;
    if (check_0(l_len + 1LL)) return;

    // Перебираем в поисках удачливости 1 (если нет и её, то чисел достаточно мало).
    lli current_num = l,
        current_luck = luckiness(l),
        best_num = l,
        best_luck = luckiness(l);
    while ((current_num <= r) and (best_luck != 1LL)) {
        current_luck = luckiness(current_num);
        if (current_luck < best_luck) {
            best_num = current_num;
            best_luck = current_luck;
        }
        ++current_num;
    }
    answer = best_num;

    return;
}

lli len(lli num) {
    lli cnt = 0LL;
    while (num) {
        ++cnt;
        num /= 10LL;
    }
    return cnt;
}

bool check_0(lli _len) {
    lli ones = 0LL; // число из единичек
    while (_len--)
        ones = ones * 10LL + 1LL;
    
    lli num;
    for (lli d = 1LL; d <= 9LL; ++d) {
        num = d * ones;
        if (l <= num and num <= r) {
            answer = num;
            return true;
        }
    }

    return false;
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
