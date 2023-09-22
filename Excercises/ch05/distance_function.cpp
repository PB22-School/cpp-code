#include <iostream>
#include <math.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dsquared = dx*dx + dy*dy;
    double result = sqrt(dsquared);
    return result;
}

int main() {
    for(int i = 1; i < 13; i++) {
        double p1x = i*12;
        double p1y = i*23;
        double p2x = i*2;
        double p2y = i*9;
        cout << "Distance of (" << p1x << "," << p1y << ") and (" << p2x << "," << p2y << ") = " << distance(p1x,p1y,p2x,p2y) << endl;
    }
    return 0;
}