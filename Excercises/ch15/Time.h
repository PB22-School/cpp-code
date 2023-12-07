#include <iostream>
#include <string>
using namespace std;

class Time {
    int hour, minute;
    double second;
public:
    Time(double secs);
    string str() const;
    void increment(double secs);
    double convert_to_seconds() const;
    Time operator + (const Time& t);
    Time operator - (const Time& t);
};

ostream& operator <<(ostream& os, const Time& t);