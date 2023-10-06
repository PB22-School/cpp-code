#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

struct Rectangle {
    Point corner;
    double width, height;
};

Point lowerRight(Rectangle rect) {
    Point out = {rect.corner.x+rect.width,rect.corner.y+rect.height};
    return out;
}

int main() {
    Rectangle rect = {{8,0},5,10};
    Point lowerRight_Point = lowerRight(rect);
    cout << "Lower Right : " << lowerRight_Point.x <<  "," << lowerRight_Point.y << endl;
}