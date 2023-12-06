#include <iostream>
#include <string>
#include "Point.h"

double Point::get_x() 
{
    return x;
}

double Point::get_y() 
{
    return y;
}

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

string Point::str() 
{
    return "(" + to_string(x) + "," + to_string(y) + ")"
}

Point Point::operator + (Point point) 
{
    return Point(x + point.get_x(), y + point.get_y());
}

Point Point::operator - (Point point) 
{
    return Point(x - point.get_x(), y - point.get_y());
}

Point Point::operator * (double scalar) 
{
    return Point(x * scalar, y * scalar)
}

double Point::operator * (Point point) 
{
    return (point.get_x() * x) + (point.get_y() * x);
}

ostream& operator<<(ostream& os, Point& p) 
{
    os << p.str();
    return os;
}