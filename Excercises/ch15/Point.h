class Point 
{
    double x, y;

public:
    double get_x();
    double get_y();

    Point();
    Point(double x, double y);

    str();
    operator + (Point point);
    operator - (Point point);

};

ostream& operator<<(ostream& os, Point& c);