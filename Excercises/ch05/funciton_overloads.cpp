#include <iostream>
using namespace std;

int overloaded_function() {
    return 5;
}
int overloaded_function(int i) {
    return 8;
}
int overloaded_function(int i, int x) {
    return 10;
}
int overloaded_function(int z, string x) {
    return 15;
}
int overloaded_function(bool m) {
    return 100;
}

int main() {
    cout << overloaded_function() << endl;
    cout << overloaded_function(1) << endl;
    cout << overloaded_function(1,2) << endl;
    cout << overloaded_function(1,"2") << endl;
    cout << overloaded_function(true) << endl;

    return 0;
}
