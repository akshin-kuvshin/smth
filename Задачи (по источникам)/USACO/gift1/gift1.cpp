/*
ID: daksion2
TASK: gift1
LANG: C++
*/

#include <fstream>
#include <string>
using namespace std;

// Constants
const int MAX_SIZE = 10;

// Variables
int size,
    moneyInBank[MAX_SIZE + 5],
    moneyInFact[MAX_SIZE + 5],
    ng[MAX_SIZE + 5];
string senders[MAX_SIZE + 5],
       np[MAX_SIZE + 5],
       recipients[MAX_SIZE + 5][MAX_SIZE + 5];

// Functions
void input();
void solution();
void output();
int getIndexOfArrayItem(string*, int, string);

int main() {
    input();
    solution();
    output();
    
    return 0;
}

void input() {
    ifstream fin("gift1.in");
    
    fin >> size;
    for (int i = 0; i < size; i++)
        fin >> np[i];
    
    for (int i = 0, j; i < size; i++) {
        fin >> senders[i];
        j = getIndexOfArrayItem(np, size, senders[i]);
        
        fin >> moneyInBank[j] >> ng[j];
        for (int k = 0; k < ng[j]; k++)
            fin >> recipients[j][k];
    }
    
    fin.close();
    return;
}

void solution() {
    for (int i = 0, j; i < size; i++) {
        j = getIndexOfArrayItem(np, size, senders[i]);
        
        if (ng[j] == 0) {
            moneyInFact[j] += -moneyInBank[j];
        } else {
            for (int k = 0, p; k < ng[j]; k++) {
                p = getIndexOfArrayItem(np, size, recipients[j][k]);
                moneyInFact[p] += moneyInBank[j] / ng[j]; 
            }
            moneyInFact[j] += -moneyInBank[j] + moneyInBank[j] % ng[j];
        }
    }
    
    return;
}

void output() {
    ofstream fout("gift1.out");
    
    for (int i = 0; i < size; i++)
        fout << np[i] << ' ' << moneyInFact[i] << '\n';
    
    fout.close();
    return;
}

int getIndexOfArrayItem(string *array, int sz, string requiredElement) {
    for (int i = 0; i < sz; i++)
        if (requiredElement == array[i])
            return i;
    return -1;
}
