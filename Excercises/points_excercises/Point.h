#include <string>
using namespace std;

class Point {
    double x, y;
public:
    string to_string() const;
    double distance(const Point& p) const;
    Point();
    Point(double x, double y);
    Point operator +(const Point& p) const;
    Point operator -(const Point& p) const;
    Point operator *(const double scalar) const;
};

Point operator*(int num, const Point& p);
Point operator*(double num, const Point& p);