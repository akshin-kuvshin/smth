#include <iostream>
#include <map>
#include <string>
using namespace std;

int N,
    sum,
    percent;
string command,
       name,
       name1,
       name2;
map<string, int> bank;

void change_balance(string&, int);
int get_balance(string&);
void accrue_percent(int);

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> command;

        if (command == "DEPOSIT") {
            cin >> name >> sum;
            change_balance(name, sum);
        } else if (command == "WITHDRAW") {
            cin >> name >> sum;
            change_balance(name, -sum);
        } else if (command == "BALANCE") {
            cin >> name;
            if (bank.find(name) == bank.end()) {
                cout << "ERROR\n";
                continue;
            }
            cout << get_balance(name) << '\n';
        } else if (command == "TRANSFER") {
            cin >> name1 >> name2 >> sum;
            change_balance(name1, -sum);
            change_balance(name2, sum);
        } else { // command == "INCOME"
            cin >> percent;
            accrue_percent(percent);
        }
    }

    return 0;
}

void change_balance(string &client, int money) {
    if (bank.find(client) == bank.end()) {
        bank[client] = money;
        return;
    }

    bank[client] += money;
    return;
}

int get_balance(string &client) {
    return bank[client];
}

void accrue_percent(int p) {
    for (map<string, int>::iterator it = bank.begin(); it != bank.end(); ++it)
        if (it->second > 0)
            it->second += it->second * p / 100;
    return;
}
