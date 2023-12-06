#include <iostream>
#include <string>
using namespace std;
class Point 
{
    double x, y;

public:
    double get_x();
    double get_y();

    Point();
    Point(double x, double y);

    string str();
    Point operator + (Point point);
    Point operator - (Point point);
    Point operator * (double scalar);
    double operator * (Point point);
};

ostream& operator<<(ostream& os, Point& c);