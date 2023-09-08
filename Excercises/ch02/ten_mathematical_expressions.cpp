#include <iostream>
using namespace std;

int a = 3;
int b = 5;
int c = 6;

int main () {
    cout << a << " + " << b << " = " << a+b << endl;
    cout << a << " - " << b << " = " << a-b << endl;
    cout << a << " * " << b << " = " << a*b << endl;
    cout << a << " / " << b << " = " << a/b << endl;
    cout << b << " - " << a << " = " << b-a << endl;
    cout << b << " / " << a << " = " << b/a << endl;
    cout << c << " + " << b << " = " << c+b << endl;
    cout << c << " - " << b << " = " << c-b << endl;
    cout << c << " / " << b << " = " << c/b << endl;
    cout << c << " * " << b << " = " << c*b << endl;
    cout << a << " - " << c << " = " << a-c << endl;
    cout << c << " + " << a << " = " << c+a << endl;
}