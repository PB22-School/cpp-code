#include <iostream>
using namespace std;

struct Time {
    int hour, minute;
    double second;
};

void increment(Time& time, double secs)
{
    time.second += secs;

    int minutes = int(secs/60);
    //these integers probably aren't needed, but it does make it a little bit faster,
    //it just uses a bit more memory.

    time.minute += minutes;

    time.second = secs-(minutes*60);

    int hours = int(time.minute/60);

    time.hour += hours;

    time.minute = time.minute-(hours*60);
}

int main() {
    Time time = {5,25,24};
    increment(time,2390);
    cout << time.hour << ":" << time.minute << ":" << time.second << endl;
}