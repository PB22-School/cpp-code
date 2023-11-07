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

int main()
{
    Time current_time(9, 14, 3);
    /*
    With the int, int, int inputs,
    The int, int, double constructor is run.

    With the creation of the int, int,
    int constructor, the function is called
    instead of the int, int, double one.
    */
}