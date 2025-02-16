// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;

const int A = 97,
          Z = 122;

bool decode(const vector<int>&, int, vector<int>&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> S(n);
    for (auto& c : S)
        cin >> c;
    
    // переберём всевозможные первые символы строки
    vector<int> ans(n); // ответ
    for (int first = A; first <= Z; ++first) {
        ans[0] = first;

        // расшифровываем строку S на основе первого символа,
        // результат заносим в ans.
        // если в процессе расшифровки мы получили символ, не являющийся
        // строчной английской буквой, то продолжаем поиск дальше.
        // если S[0] != ans[0] ^ ans[1], то расшифровка неверна, тоже продолжаем поиск дальше.
        // иначе расшифровка прошла успешно, заканчиваем поиск.
        if (decode(S, n, ans))
            break;
    }

    for (auto c : ans)
        cout << (char)c;
    cout << '\n';
    return 0;
}

bool decode(const vector<int>& S, int n, vector<int>& ans) {
    ans[n - 1] = S[n - 1] ^ ans[0];
    for (int i = n - 2; i > 0; --i) {
        ans[i] = S[i] ^ ans[i + 1];
        if (ans[i] < A or Z < ans[i])
            return false;
    }
    return (S[0] == (ans[0] ^ ans[1]));
}
