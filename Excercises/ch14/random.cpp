#include <cstdlib>
#include <ctime>
using namespace std;

int random_between(int l, int h) {
    if (l < 0 || h < 0) {
        return -1;
    }
    else if (h <= l) {
        int t = l;
        l = h;
        h = t;
    }
    else if (l == h) {
        return l;
    }

    int difference = h - l + 1;
    return l + rand() % difference;
}