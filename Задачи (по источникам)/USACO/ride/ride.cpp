/*
ID: daksion2
TASK: ride
LANG: C++
*/

#include <fstream>
using namespace std;

// Constants
const int MAX_SIZE = 6;

// Variables
int prod_comet,
    prod_group,
    mod_comet,
    mod_group;
char comet[MAX_SIZE + 5],
     group[MAX_SIZE + 5];
bool go;

// Functions
void input();
void solution();
void output();

int main() {
    input();
    solution();
    output();
    
    return 0;
}

void input() {
    ifstream fin("ride.in");
    fin >> comet >> group;
    fin.close();
    
    return;
}

void solution() {
    prod_comet = 1;
    for (int i = 0; (i < 6) and (comet[i] != '\0'); i++)
        prod_comet *= comet[i] - 64;
    prod_group = 1;
    for (int i = 0; (i < 6) and (group[i] != '\0'); i++)
        prod_group *= group[i] - 64;
    
    mod_comet = prod_comet % 47;
    mod_group = prod_group % 47;
    
    go = (mod_comet == mod_group);
    
    return;
}

void output() {
    ofstream fout("ride.out");
    fout << (go ? "GO" : "STAY") << '\n';
    fout.close();
    
    return;
}
