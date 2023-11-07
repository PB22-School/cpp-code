#include "Fraction.h"
#include <iostream>
using namespace std;

int main() {
    Fraction fraction(1,5);
    Fraction fraction2(5,10);
    fraction.plus(fraction2);
    /*
        10     25       35          7
        -  +  -    =    -     =     -
        50     50       50          10
    */
    cout << fraction.to_string() << endl;
}