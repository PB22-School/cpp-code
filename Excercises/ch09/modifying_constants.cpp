#include <iostream>
using namespace std;

void AddOne_Print(const int x) {
    x+=1;
    cout << x;
}

int main() {
    AddOne_Print(400);
}

/*
The code throws an error and says that it cannot assign
to a constant type.
*/