#include <iostream>
using namespace std;

void returnNothing() {
    cout << "returning Nothing" << endl;
}

int main() {
    returnNothing() + 7;
    cout << "The line above generates an error when compiled." << endl;
    return 0;
}