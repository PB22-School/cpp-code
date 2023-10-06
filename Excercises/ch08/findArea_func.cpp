#include <iostream>
using namespace std;

struct Point {
    double x,y;
};

struct Rectangle {
    Point corner;
    double width,height;
};

double findArea(Rectangle rect) {
    return rect.height*rect.width;
}

int main() {
    Rectangle rect = {{8,3},9,5};
    cout << "Area is " << findArea(rect) << endl;
}