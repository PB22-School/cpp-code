#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

string Time::str() const 
{
    return to_string(hour) + ':' + to_string(minute) + ':' + to_string(second);
}

void Time::increment(double secs) 
{
    second += secs;
    minute += int(secs / 60);
    second -= int(secs / 60) * 60;
    hour += int(minute / 60);
    minute -= int(minute / 60) * 60;
}

double Time::convert_to_seconds() const
{
    int minutes = hour * 60 + minute;
    double seconds = minutes * 60 + second;

    return seconds;
}

Time::Time(double secs)
{
    hour = int(secs / 3600.0);
    secs -= hour * 3600.0;
    minute = int(secs / 60.0);
    secs -= minute * 60;
    second = secs;
}

Time Time::operator + (const Time& t) 
{
    return Time(convert_to_seconds() + t.convert_to_seconds());
}

Time Time::operator - (const Time& t) 
{
    return Time(convert_to_seconds() - t.convert_to_seconds());
}

ostream& operator << (ostream& os, const Time& t) 
{
    os << t.str();
    return os;
}