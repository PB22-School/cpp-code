#include <iostream>
using namespace std;

void compare(int a, int b) {
    if(a==b) {
        cout << a << " is equal to " << b << endl;
    }
    else if(a>b) {
        cout << a << " is greater than " << b << endl; 
    }
    else {
        cout << a << " is less than " << b << endl;
    }
}

int main() {
    compare(4,5);
}