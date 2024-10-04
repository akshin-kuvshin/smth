#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Variables
int antennasAmount;
vector<int> x;
vector<int> y;
int x_tmp;
int y_tmp;
double rMin = -1;

// Functions
void arraysInput();
double distanceBetweenPoints(int, int);
void setRMinInMaxDistance();

int main() {
    // Input
    cin >> antennasAmount;
    arraysInput();

    // Algorithm
    setRMinInMaxDistance();

    // Output
    cout.precision(8);
    cout << rMin / 2 << '\n';

    return 0;
}

void arraysInput() {
    for (int i = 0; i < antennasAmount; i += 1) {
        cin >> x_tmp >> y_tmp;
        x.push_back(x_tmp);
        y.push_back(y_tmp);
    }
}

double distanceBetweenPoints(int i, int j) {
    return sqrt(pow(x.at(i) - x.at(j), 2) + pow(y.at(i) - y.at(j), 2));
}

void setRMinInMaxDistance() {
    for (int i = 0; i < antennasAmount; i++)
        for (int j = 0; j < antennasAmount; j++)
            if (rMin < distanceBetweenPoints(i, j))
                rMin = distanceBetweenPoints(i, j);
}
