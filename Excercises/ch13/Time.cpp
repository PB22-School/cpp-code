#include "Time.h"
#include <iostream>
using namespace std;

Time::Time(int h, int m, double s) {
    hour = h; minute = m; second = s;
    cout << "int, int, double" << endl;
}

Time::Time(int h, int m, int s) {
    cout << "int, int, int" << endl;
}

Time::Time(double secs) {
    hour = int(secs / 3600.0);
    secs -= hour * 3600.0;
    minute = int(secs / 60.0);
    secs -= minute * 60;
    second = secs;
    cout << "double" << endl;
}

void Time::increment(double secs) {
    second += secs;
    minute += int(second / 60);
    second -= int(second / 60) * 60;
    hour += int(minute / 60);
    minute -= int(minute / 60) * 60;
}

string Time::to_string() const
{
    return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second) + "\n";
}