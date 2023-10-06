#include <cstdlib>
#include <iostream>
using namespace std;

void random_numbers() {
    srand((unsigned) time(NULL));
    for(int i = 0; i < 10; i++) {
        cout << i << "\t" << (rand() % 10)+1 << endl;
    }
}

int main() {
    random_numbers();
}