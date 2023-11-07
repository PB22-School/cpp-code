#include "Time.h"
#include "math.h"
void Time::increment(double secs) {
    second += secs;
    minute += int(second / 60);
    second -= int(second / 60) * 60;
    hour += int(minute / 60);
    minute -= int(minute / 60) * 60;
}