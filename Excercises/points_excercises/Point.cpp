#include <string>
#include "Point.h"
#include <cmath>
using namespace std;

string Point::to_string() const {
    return '(' + std::to_string((int)x) + ", " + std::to_string((int)y) + ')';
}

double Point::distance(const Point& p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point Point::operator +(const Point& p) const {
    return Point(x + p.x, y + p.y);
}

Point Point::operator -(const Point& p) const {
    return Point(x - p.x, y - p.y);
}

Point Point::operator *(const double scalar) const {
    return Point(x * scalar, y * scalar);
}

Point operator*(int num, const Point& p) {
    return p * num;
}

Point operator*(double num, const Point& p) {
    return p * num;
}