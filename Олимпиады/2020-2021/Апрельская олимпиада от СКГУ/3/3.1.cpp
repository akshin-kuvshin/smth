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
double r_tmp;

// Functions
void arraysInput();
double distanceBetweenPoints(int, int);
void setRMinInMaxDistance();
void rMinFinding();
bool isGoodRadius();

int main() {
    // Input
    cin >> antennasAmount;
    arraysInput();

    // Algorithm
    setRMinInMaxDistance();
    rMinFinding();

    // Output
    cout.precision(8);
    cout << rMin << '\n';

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

void rMinFinding() {
    for (int i = 0; i < antennasAmount; i++)
        for (int j = i + 1; j < antennasAmount; j++) {
            r_tmp = distanceBetweenPoints(i, j) / 2;
            if (r_tmp < rMin and isGoodRadius())
                rMin = r_tmp;
        }
}

bool isGoodRadius() {
    for (int i = 0; i < antennasAmount; i++)
        for (int j = i + 1; j < antennasAmount; j++)
            if (r_tmp * 2 < distanceBetweenPoints(i, j))
                return false;
    return true;
}
