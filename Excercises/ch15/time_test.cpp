#include "Time.h"
#include <iostream>
using namespace std;

int main() 
{
    Time t(1230);
    Time t2(1230);

    Time t3 = t + t2;
    cout << t3 << endl;
}