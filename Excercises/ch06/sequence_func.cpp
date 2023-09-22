#include <iostream>
using namespace std;

void sequence(int n) {
    while (n!=1) {
        cout << n << endl;
        if(n%2 == 0) {
            n = n/2;
        }
        else {
            n = n * 3 + 1;
        }
    }
}

int main() {
    for(int i = 2; i < 10; i++) {
        cout << "Running sequence with " << i*8 << endl;
        sequence(i*8);
        cout << endl;
    }
    cout << endl << "Whenever I try this, it always gets to 2 then breaks, no matter which numbers I put in." << endl;
    cout << endl << "I also saw that 1 is never printed, because it the print statement comes after the conditional and before the re-assignment." << endl;
    cout << endl << "Also the multiples of 8 that I tried from 24 up all go 10,5,16,8,4,2." << endl << endl;
    return 0;
}