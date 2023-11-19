#include "random.h"
#include <iostream>
using namespace std;

int main() {
    srand((unsigned) time(NULL));
    for (int i = 0; i < 10; i++) {
        cout << random_between(19,21) << endl;
    }
}